#ifndef PimaryGeneratorAction_h
#define PimaryGeneratorAction_h

#include "G4VUserPrimaryGeneratorAction.hh"
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

        //method to access particle gun
        const G4ParticleGun* GetParticleGun() const { return fParticleGun; }

    private:
        G4ParticleGun* fParticleGun;
};

#endif
