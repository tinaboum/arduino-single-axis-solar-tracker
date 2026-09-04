# Wiring and integration notes

Only the firmware-confirmed interfaces are listed here. This document intentionally does not invent a full circuit schematic or component ratings that were absent from the project material.

## Verified controller interfaces

| Device signal | Controller pin | Direction |
|---|---:|---|
| Left LDR analog signal | `A0` | Input |
| Right LDR analog signal | `A1` | Input |
| Servo control signal | `9` | Output |

## Integration requirements

- Each LDR must be part of a suitable analog conditioning circuit whose output remains within the controller ADC input range.
- The two sensor channels should use matched components and symmetrical physical placement where practical.
- The controller and servo supply must share a common ground.
- Size the servo power source for the actuator's stall current. Do not assume that the controller board regulator can safely supply the motor.
- Establish safe mechanical limits first, then set `MIN_ANGLE` and `MAX_ANGLE` in the firmware.
- Test the mechanism with the panel unloaded or supported before a full-range movement test.

## Items requiring confirmation for reproduction

- Arduino board model and logic/ADC voltage
- Servo model, supply voltage, and stall current
- LDR part numbers and resistor values
- Solar-panel voltage, current, and mass
- Mechanical linkage geometry and safe travel range
- Power-distribution and protection components
