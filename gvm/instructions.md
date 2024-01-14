
# Gismo Virtual Machine - Instruction Set #
| Instruction        | Parameter   | Stack-Parameter                     | Description                                      |
| ------------------ | ----------- | ----------------------------------- | ------------------------------------------------ |
| Nop                | ()          | ()                                  | Will be ignored by the GVM                       |
| LoadConstNum8      | (id: num32) | () -> num8                          | Loads an 8 bit part of the constant num8 register |
| LoadConstNum16     | (id: num32) | () -> num16                         | Loads an 16 bit part of the constant num16 register                                                 |
| LoadConstNum32     | (id: num32) | () -> num32                         |                                                  |
| LoadConstNum64     | (id: num32) | () -> num64                         |                                                  |
| LoadGlobalNum8     | (id: num32) | () -> num8                          |                                                  |
| LoadGlobalNum16    | (id: num32) | () -> num16                         |                                                  |
| LoadGlobalNum32    | (id: num32) | () -> num32                         |                                                  |
| LoadGlobalNum64    | (id: num32) | () -> num64                         |                                                  |
| StoreGlobalNum8    | (id: num32) | (val: num8)                         |                                                  |
| StoreGlobalNum16   | (id: num32) | (val: num16)                        |                                                  |
| StoreGlobalNum32   | (id: num32) | (val: num32)                        |                                                  |
| StoreGlobalNum64   | (id: num32) | (val: num64)                        |                                                  |
| LoadLocalNum8      | (id: num32) | () -> num8                          |                                                  |
| LoadLocalNum16     | (id: num32) | () -> num16                         |                                                  |
| LoadLocalNum32     | (id: num32) | () -> num32                         |                                                  |
| LoadLocalNum64     | (id: num32) | () -> num64                         |                                                  |
| StoreLocalNum8     | (id: num32) | (val: num8)                         |                                                  |
| StoreLocalNum16    | (id: num32) | (val: num16)                        |                                                  |
| StoreLocalNum32    | (id: num32) | (val: num32)                        |                                                  |
| StoreLocalNum64    | (id: num32) | (val: num64)                        |                                                  |
| AddI               | ()          | (a: int64, b: int64) -> int64       |                                                  |
| AddU               | ()          | (a: uint64, b: uint64) -> uint64    |                                                  |
| AddF               | ()          | (a: float64, b: float64) -> float64 |                                                  |
| SubI               | ()          | (a: int64, b: int64) -> int64       |                                                  |
| SubU               | ()          | (a: uint64, b: uint64) -> uint64    |                                                  |
| SubF               | ()          | (a: float64, b: float64) -> float64 |                                                  |
| MulI               | ()          | (a: int64, b: int64) -> int64       |                                                  |
| MulU               | ()          | (a: uint64, b: uint64) -> uint64    |                                                  |
| MulF               | ()          | (a: float64, b: float64) -> float64 |                                                  |
| DivI               | ()          | (a: int64, b: int64) -> int64       |                                                  |
| DivU               | ()          | (a: uint64, b: uint64) -> uint64    |                                                  |
| DivF               | ()          | (a: float64, b: float64) -> float64 |                                                  |
| And                | ()          | (a: num64, b: num64) -> num64       |                                                  |
| Or                 | ()          | (a: num64, b: num64) -> num64       |                                                  |
| Not                | ()          | (x: num64) -> num64                 |                                                  |
| EqI                | ()          | (a: int64, b: int64) -> num64       |                                                  |
| EqU                | ()          | (a: uint64, b: uint64) -> num64     |                                                  |
| EqF                | ()          | (a: float64, b: float64) -> num64   |                                                  |
| EqIU               | ()          |                                     |                                                  |
| EqFI               | ()          |                                     |                                                  |
| EqFU               | ()          |                                     |                                                  |
| GreaterI           | ()          |                                     |                                                  |
| GreaterU           | ()          |                                     |                                                  |
| GreaterF           | ()          |                                     |                                                  |
| GreaterIU          | ()          |                                     |                                                  |
| GreaterFI          | ()          |                                     |                                                  |
| GreaterFU          | ()          |                                     |                                                  |
| LessI              | ()          |                                     |                                                  |
| LessU              | ()          |                                     |                                                  |
| LessF              | ()          |                                     |                                                  |
| LessIU             | ()          |                                     |                                                  |
| LessFI             | ()          |                                     |                                                  |
| LessFU             | ()          |                                     |                                                  |
| LoadGlobalCmplx    | (id: num32) |                                     |                                                  |
| LoadLocalCmplx     | (id: num32) |                                     |                                                  |
| StoreGlobalCmplx   | (id: num32) |                                     |                                                  |
| StoreLocalCmplx    | (id: num32) |                                     |                                                  |
| CmplxAddElement    |             |                                     |                                                  |
| CmplxRemoveElement |             |                                     |                                                  |
| CmplxSize          |             |                                     |                                                  |
| CmplxLoadElement   |             |                                     |                                                  |
| CmplxStoreElement  |             |                                     |                                                  |
| LoadConstFunc      |             |                                     |                                                  |
| LoadGlobalFunc     |             |                                     |                                                  |
| LoadLocalFunc      |             |                                     |                                                  |
| StoreGlobalFunc    |             |                                     |                                                  |
| StoreLocalFunc     |             |                                     |                                                  |
| CallFunc           |             |                                     |                                                  |
| ReturnElement      |             |                                     |                                                  |
| Pop                |             |                                     |                                                  |
| Swap               |             |                                     |                                                  |
| Rot                |             |                                     |                                                  |
| Exit               |             |                                     |                                                  |
| LoadConstText      |             |                                     |                                                  |
| LoadGlobalText     |             |                                     |                                                  |
| LoadLocalText      |             |                                     |                                                  |
| StoreGlobalText    |             |                                     |                                                  |
| StoreLocalText     |             |                                     |                                                  |
| TextAddChar        |             |                                     |                                                  |
| TextRemoveChar     |             |                                     |                                                  |
| TextPopChar        |             |                                     |                                                  |
| TextGetSize        |             |                                     |                                                  |
| TextGetChar        |             |                                     |                                                  |
| CmplxClone         |             |                                     |                                                  |
| TextClone          |             |                                     |                                                  |
| PrintI             |             |                                     |                                                  |
| PrintU             |             |                                     |                                                  |
| PrintF             |             |                                     |                                                  |
| PrintC             |             |                                     |                                                  |
| PrintText          |             |                                     |                                                  |
| Newline            |             |                                     |                                                  |
| Cmplx2Text         |             |                                     |                                                  |
| GetInstance        |             |                                     |                                                  |
| JumpAbs            |             |                                     |                                                  |
| JumpNeg            |             |                                     |                                                  |
| JumpPos            |             |                                     |                                                  |
| JumpAbsIfTrue      |             |                                     |                                                  |
| JumpAbsIfFalse     |             |                                     |                                                  |
| JumpNegIfTrue      |             |                                     |                                                  |
| JumpNegIfFalse     |             |                                     |                                                  |
| JumpPosIfTrue      |             |                                     |                                                  |
| JumpPosIfFalse     |             |                                     |                                                  |
| ModI               |             |                                     |                                                  |
| ModU               |             |                                     |                                                  |
| CmplxBuildEmpty    |             |                                     |                                                  |
| CmplxBuildNew      |             |                                     |                                                  |
| InputI             |             |                                     |                                                  |
| InputU             |             |                                     |                                                  |
| InputF             |             |                                     |                                                  |
| InputText          |             |                                     |                                                  |
| InputLine          |             |                                     |                                                  |
| TextSetChar        |             |                                     |                                                  |
| LoadArgument       |             |                                     |                                                  |
| I2U                |             |                                     |                                                  |
| I2F                |             |                                     |                                                  |
| U2I                |             |                                     |                                                  |
| U2F                |             |                                     |                                                  |
| F2I                |             |                                     |                                                  |
| F2U                |             |                                     |                                                  |
| IsNum              |             |                                     |                                                  |
| IsText             |             |                                     |                                                  |
| IsCmplx            |             |                                     |                                                  |
| IsFunc             |             |                                     |                                                  |
| IsNothing          |             |                                     |                                                  |
| Float2Double       |             |                                     |                                                  |
| Double2Float       |             |                                     |                                                  |
| BNot               |             |                                     |                                                  |
| CmplxInit          |             |                                     |                                                  |
| I2Text             |             |                                     |                                                  |
| F2Text             |             |                                     |                                                  |
| U2Text             |             |                                     |                                                  |
| Text2I             |             |                                     |                                                  |
| Text2F             |             |                                     |                                                  |
| Text2U             |             |                                     |                                                  |
| UnaryMinusI        |             |                                     |                                                  |
| UnaryMinusF        |             |                                     |                                                  |
| TextConcat         |             |                                     |                                                  |
| InputChar          |             |                                     |                                                  |
| CallAsync          |             |                                     |                                                  |
| Clock              |             |                                     |                                                  |
| Time               |             |                                     |                                                  |
| GllLoad            |             |                                     |                                                  |
| GllSymbol          |             |                                     |                                                  |
| GllExec            |             |                                     |                                                  |
| GllClose           |             |                                     |                                                  |
| SetupIter          |             |                                     |                                                  |
| NextIter           |             |                                     |                                                  |
| TextHash           |             |                                     |                                                  |
| Hint               |             |                                     |                                                  |
| ShiftL             |             |                                     |                                                  |
| ShiftR             |             |                                     |                                                  |
