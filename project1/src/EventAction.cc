#include "EventAction.hh"
#include "RunAction.hh"

#include "G4AnalysisManager.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"


EventAction::EventAction(RunAction* runAction)
: fRunAction(runAction)
{}


void EventAction::BeginOfEventAction(const G4Event*)
{
    // Initialization per event
    fEdep = 0.;

    fEnergyAbs = 0.;
    fEnergyGap = 0.;
    //fLengthAbs = 0.;
    //fLengthGap = 0.;
}

void EventAction::EndOfEventAction(const G4Event*)
{
    // accumulate statistics in run action
    fRunAction->AddEdep(fEdep);

    // Get analysis manager
    auto analysisManager = G4AnalysisManager::Instance();

    // Fill ntuple
    analysisManager->FillNtupleDColumn(0, fEnergyAbs);
    analysisManager->FillNtupleDColumn(1, fEnergyGap);
    //analysisManager->FillNtupleDColumn(2, fLengthAbs);
    //analysisManager->FillNtupleDColumn(3, fLengthGap);
    analysisManager->AddNtupleRow();
}
