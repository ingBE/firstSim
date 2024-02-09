#include "RunAction.hh"

RunAction::RunAction()
    : G4UserRunAction()
{
}

RunAction::~RunAction()
{
    delete G4AnalysisManager::Instance();
}

void RunAction::BeginOfRunAction(const G4Run*)
{
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    G4String fileName = "secondSim.root";
    analysisManager->OpenFile(fileName);
    G4cout << "Using " << analysisManager->GetType() << G4endl;

    analysisManager->CreateNtuple("step", "step");
    analysisManager->CreateNtupleIColumn("eventID");
    analysisManager->CreateNtupleIColumn("volumeID");
    analysisManager->CreateNtupleDColumn("edep");
    analysisManager->FinishNtuple();
}

void RunAction::EndOfRunAction(const G4Run*)
{
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}
