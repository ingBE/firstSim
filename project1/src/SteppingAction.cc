#include "SteppingAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"

SteppingAction::SteppingAction(EventAction* eventAction)
: fEventAction(eventAction)
{}

void SteppingAction::UserSteppingAction(const G4Step* step)
{
    /*
    if (!fScoringVolume) {
        const auto detConstruction = static_cast<const DetectorConstruction*>(
          G4RunManager::GetRunManager()->GetUserDetectorConstruction());
        fScoringVolume = detConstruction->GetScoringVolume();
    }

    // get logical volume of the current step
    G4LogicalVolume* volume
        = step->GetPreStepPoint()->GetTouchableHandle()
        ->GetVolume()->GetLogicalVolume();

    // check if we are in scoring volume
    if (volume != fScoringVolume) return;
    */

    // collect energy deposited in this step
    G4double edep = step->GetTotalEnergyDeposit();
    fEventAction->AddEdep(edep);

    // get physical volume of the current step
    G4VPhysicalVolume* physVolume = step->GetPreStepPoint()->GetPhysicalVolume();

    if ( physVolume->GetCopyNo() == 1 )
        fEventAction->AddEnv(edep);

    if ( physVolume->GetCopyNo() == 2 )
        fEventAction->AddMat1(edep);

    if ( physVolume->GetCopyNo() == 3 )
        fEventAction->AddMat2(edep);

    if ( physVolume->GetCopyNo() == 4 )
        fEventAction->AddMat3(edep);
}
