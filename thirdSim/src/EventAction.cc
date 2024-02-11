#include "EventAction.hh"

EventAction::EventAction()
    :G4UserEventAction()
{
}

EventAction::~EventAction()
{
}

void EventAction::BeginOfEventAction(const G4Event*)
{
    edep1 = 0.;
}

void EventAction::EndOfEventAction(const G4Event*)
{
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    analysisManager->FillNtupleDColumn(1, 0, edep1);
    analysisManager->AddNtupleRow(1);
}
