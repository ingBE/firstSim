#include "EventAction.hh"
#include "RunAction.hh"

#include "G4AnalysisManager.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"


EventAction::EventAction(RunAction* runAction)
: fRunAction(runAction)
{}


void EventAction::BeginOfEventAction(const G4Event*)
{
    // Initialization per event
    fEdep = 0.;

    fEnergyEnv = 0.;
    fEnergyMat1 = 0.;
    fEnergyMat2 = 0.;
    fEnergyMat3 = 0.;
}

void EventAction::EndOfEventAction(const G4Event*)
{
    // accumulate statistics in run action
    fRunAction->AddEdep(fEdep);

    // Get analysis manager
    auto analysisManager = G4AnalysisManager::Instance();

    // Fill ntuple
    analysisManager->FillNtupleDColumn(0, fEnergyEnv / eV);
    analysisManager->FillNtupleDColumn(1, fEnergyMat1 / eV);
    analysisManager->FillNtupleDColumn(2, fEnergyMat2 / eV);
    analysisManager->FillNtupleDColumn(3, fEnergyMat3 / eV);
    analysisManager->AddNtupleRow();
}
