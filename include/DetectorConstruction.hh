#ifndef DetectorConstruction_h
#define DetectorConstruction_h

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction
{
    public:
        DetectorConstruction() = default;
        ~DetectorConstruction() override = default;

        G4VPhysicalVolume* Construct() override;

    protected:

};

#endif
