#ifndef SteppingAction_h
#define SteppingAction_h

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "globals.hh"

class SteppingAction : public G4UserSteppingAction
{
    public:
        SteppingAction();
        ~SteppingAction() override;

        // method from the base calss
        void UserSteppingAction(const G4Step* step) override;

    private:

};

#endif
