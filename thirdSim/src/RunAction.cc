#include "RunAction.hh"

RunAction::RunAction()
    : G4UserRunAction()
{
    fFilename = "data.root";
}

RunAction::RunAction(G4String name)
    : G4UserRunAction()
{
    fFilename = name+".root";
}

RunAction::~RunAction()
{
    delete G4AnalysisManager::Instance();
}

void RunAction::BeginOfRunAction(const G4Run*)
{
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    analysisManager->OpenFile(fFilename);
    G4cout << "Using " << analysisManager->GetType() << G4endl;

    analysisManager->CreateNtuple("step", "step");
    analysisManager->CreateNtupleIColumn("eventID");
    analysisManager->CreateNtupleIColumn("volumeID");
    analysisManager->CreateNtupleDColumn("edep");
    analysisManager->FinishNtuple();

    analysisManager->CreateNtuple("event", "energy deposit per event in volume-1");
    analysisManager->CreateNtupleDColumn("edep1");
    analysisManager->FinishNtuple();
}

void RunAction::EndOfRunAction(const G4Run*)
{
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}
