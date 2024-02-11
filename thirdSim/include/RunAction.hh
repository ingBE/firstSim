#ifndef RunAction_h
#define RunAction_h

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "globals.hh"
#include "G4AnalysisManager.hh"

class RunAction : public G4UserRunAction
{
    public:
        RunAction();
        RunAction(G4String name);
        ~RunAction() override;

        void BeginOfRunAction(const G4Run*) override;
        void   EndOfRunAction(const G4Run*) override;

    private:
        G4String fFilename;
};

#endif
