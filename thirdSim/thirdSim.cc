#include "globals.hh"

#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "SteppingAction.hh"
#include "EventAction.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "QGSP_BERT.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

int main(int argc, char** argv)
{
    G4RunManager* runManager = new G4RunManager;

    G4VModularPhysicsList* physicsList = new QGSP_BERT;
    runManager->SetUserInitialization(physicsList);
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserAction(new PrimaryGeneratorAction());
    runManager->SetUserAction(new RunAction());
    runManager->SetUserAction(new SteppingAction());
    runManager->SetUserAction(new EventAction());
    runManager->Initialize();

    G4VisManager* visManager = new G4VisExecutive(argc, argv);
    visManager->Initialize();

    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    if (argc != 1)
    {
        G4String command ="/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }
    else
    {
        G4UIExecutive* ui = new G4UIExecutive(argc, argv);
        UImanager->ApplyCommand("/control/execute init_vis.mac");
        ui->SessionStart();
        delete ui;
    }

    delete visManager;
    delete runManager;

    return 0;
}
