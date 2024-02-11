#ifndef EventAction_h
#define EventAction_h

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4AnalysisManager.hh"
#include "globals.hh"

class EventAction : public G4UserEventAction
{
    public:
        EventAction();
        ~EventAction() override;

        // method from the base class
        void BeginOfEventAction(const G4Event*) override;
        void EndOfEventAction(const G4Event*) override;

        void AddEnergyDeposit(G4double edep) { edep1 += edep; }

    private:
        G4double edep1;
};

#endif
