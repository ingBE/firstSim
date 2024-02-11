#ifndef PimaryGeneratorAction_h
#define PimaryGeneratorAction_h

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleGun.hh"
#include "G4Event.hh"
#include "globals.hh"

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
    public:
        PrimaryGeneratorAction();
        ~PrimaryGeneratorAction() override;

        // method from the base class
        void GeneratePrimaries(G4Event*) override;

    private:
        G4GeneralParticleSource* fParticleGun;
};

#endif
