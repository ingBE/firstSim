#include "SteppingAction.hh"
#include "EventAction.hh"

#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Event.hh"
#include "G4AnalysisManager.hh"

#include "G4EventManager.hh"

SteppingAction::SteppingAction()
    : G4UserSteppingAction()
{
}

SteppingAction::~SteppingAction()
{
}

void SteppingAction::UserSteppingAction(const G4Step* step)
{
    G4int eventID = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
    G4int volumeID = step->GetPreStepPoint()->GetPhysicalVolume()->GetCopyNo();
    G4double totalEdep = step->GetTotalEnergyDeposit();

    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillNtupleIColumn(0, eventID);
    analysisManager->FillNtupleIColumn(1, volumeID);
    analysisManager->FillNtupleDColumn(2, totalEdep);
    analysisManager->AddNtupleRow();

    EventAction* eventAction = (EventAction *) G4EventManager::GetEventManager()->GetUserEventAction();
    eventAction->AddEnergyDeposit(totalEdep);
}
