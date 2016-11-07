/***********************************************************************\
 * This software is licensed under the terms of the GNU General Public *
 * License version 3 or later. See G4CMP/LICENSE for the full license. *
\***********************************************************************/

#ifndef G4CMPGeometryUtils_hh
#define G4CMPGeometryUtils_hh 1

// $Id$
// File: G4CMPGeometryUtils.hh
//
// Description: Free standing helper functions for geometry based calculations.
//
// 20161107  Rob Agnese

#include "G4ThreeVector.hh"

class G4VPhysicalVolume;

namespace G4CMP {

G4ThreeVector GetLocalDirection(const G4VPhysicalVolume* pv,
                                const G4ThreeVector& dir);

G4ThreeVector GetLocalPosition(const G4VPhysicalVolume* pv,
                               const G4ThreeVector& pos);

G4ThreeVector GetGlobalDirection(const G4VPhysicalVolume* pv,
                                 const G4ThreeVector& dir);

G4ThreeVector GetGlobalPosition(const G4VPhysicalVolume* pv,
                                const G4ThreeVector& pos);

void RotateToLocalDirection(const G4VPhysicalVolume* pv,
                            G4ThreeVector& dir);

void RotateToLocalPosition(const G4VPhysicalVolume* pv,
                           G4ThreeVector& pos);

void RotateToGlobalDirection(const G4VPhysicalVolume* pv,
                             G4ThreeVector& dir);

void RotateToGlobalPosition(const G4VPhysicalVolume* pv,
                            G4ThreeVector& pos);
}
#endif
