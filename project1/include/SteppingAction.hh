#ifndef B1SteppingAction_h
#define B1SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class G4LogicalVolume;
class EventAction;

/// Stepping action class

class SteppingAction : public G4UserSteppingAction
{
    public:
        SteppingAction(EventAction* eventAction);
        ~SteppingAction() override = default;

        // method from the base class
        void UserSteppingAction(const G4Step*) override;

    private:
        EventAction* fEventAction = nullptr;
        G4LogicalVolume* fScoringVolume = nullptr;
};

#endif
