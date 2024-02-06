#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    // Get nist material manager
    G4NistManager* nist = G4NistManager::Instance();

    //
    // World
    //
    G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
    G4double world_size = 100*mm;

    G4Box* solidWorld = new G4Box("World",                  // its name
        0.5*world_size, 0.5*world_size, 0.5*world_size);    // its size

    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld,   // its solid
        world_mat,                                                  // its material
        "World");                                                   // its name

    G4VPhysicalVolume* physWorld = new G4PVPlacement(0,     // no rotation
        G4ThreeVector(),                                    // at (0,0,0)
        logicWorld,                                         // its logic volume
        "World",                                            // its name
        0,                                                  // its mother volume
        false,                                              // no boolean operation
        0,                                                  // copy number
        true);                                              // overlaps checking

    //
    // Detector
    //
    G4Element* elementC = nist->FindOrBuildElement("C", false);
    G4Element* elementH = nist->FindOrBuildElement("H", false);
    G4Material* detector_mat = new G4Material("Scintillator", 1.05*g/cm3, 2, kStateSolid);
    detector_mat->AddElement(elementC, 10);
    detector_mat->AddElement(elementH, 11);

    G4double detector_size = 20*mm;
    G4double detector_offset_z = 30*mm;

    G4Box* solidDetector = new G4Box("Detector",    
        0.5*detector_size, 0.5*detector_size, 0.5*detector_size);

    G4LogicalVolume* logicDetector = new G4LogicalVolume(solidDetector,    // its solid
        detector_mat,   // its material
        "Detector");    // its name

    new G4PVPlacement(0,    // no rotation
        G4ThreeVector(0,0,detector_offset_z),    // at (0,0,30mm)
        logicDetector,     // its logical volume
        "Detector",         // its name
        logicWorld,         // its mother volume
        false,              // no boolean operation
        1,                  // overlaps checking
        true);

    return physWorld;
}
