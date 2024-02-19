#ifndef B1EventAction_h
#define B1EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class RunAction;

/// Event action class

class EventAction : public G4UserEventAction
{
    public:
        EventAction(RunAction* runAction);
        //EventAction() = default;
        ~EventAction() override = default;

        void BeginOfEventAction(const G4Event* event) override;
        void EndOfEventAction(const G4Event* event) override;

        void AddEdep(G4double edep) { fEdep += edep; }

        void AddAbs(G4double de);
        void AddGap(G4double de);
        //void AddAbs(G4double de, G4double dl);
        //void AddGap(G4double de, G4double dl);

    private:
        RunAction* fRunAction = nullptr;
        G4double   fEdep = 0.;

        G4double    fEnergyAbs = 0.;
        G4double    fEnergyGap = 0.;
        //G4double    fLengthAbs = 0.;
        //G4double    fLengthGap = 0.;
};

// inline functions
inline void EventAction::AddAbs(G4double de) { fEnergyAbs += de; }
inline void EventAction::AddGap(G4double de) { fEnergyGap += de; }
/*
inline void EventAction::AddAbs(G4double de, G4double dl) {
    fEnergyAbs += de;
    fLengthAbs += dl;
}

inline void EventAction::AddGap(G4double de, G4double dl) {
    fEnergyGap += de;
    fLengthGap += dl;
}
*/

#endif
