/***********************************************************************\
 * This software is licensed under the terms of the GNU General Public *
 * License version 3 or later. See G4CMP/LICENSE for the full license. *
\***********************************************************************/

// 20200331  G4CMP-195/196: Added impact ionization and trapping

#ifndef G4CMPDriftTrappingProcess_h
#define G4CMPDriftTrappingProcess_h 1

#include "G4CMPVDriftProcess.hh"

class G4CMPEnergyPartition;


class G4CMPDriftTrappingProcess : public G4CMPVDriftProcess {
public:
  G4CMPDriftTrappingProcess(const G4String& name = "G4CMPChargeTrapping");
  virtual ~G4CMPDriftTrappingProcess();

  virtual G4double PostStepGetPhysicalInteractionLength(const G4Track& track,
                                                   G4double previousStepSize,
                                                   G4ForceCondition* condition);

  virtual G4VParticleChange* PostStepDoIt(const G4Track&, const G4Step&);

protected:
  virtual G4double GetMeanFreePath(const G4Track&, G4double, G4ForceCondition*);

  // Decide and apply different surface actions; subclasses may override
  virtual G4bool AbsorbTrack(const G4Track& aTrack, const G4Step& aStep) const;

  virtual void DoAbsorption(const G4Track& aTrack, const G4Step& aStep,
			    G4ParticleChange& aParticleChange);

private:
  G4CMPEnergyPartition* partitioner;

  // No copying/moving
  G4CMPDriftTrappingProcess(G4CMPDriftTrappingProcess&);
  G4CMPDriftTrappingProcess(G4CMPDriftTrappingProcess&&);
  G4CMPDriftTrappingProcess& operator=(const G4CMPDriftTrappingProcess&);
  G4CMPDriftTrappingProcess& operator=(const G4CMPDriftTrappingProcess&&);
};

#endif	/* G4CMPDriftTrappingProcess_h */
