macro_rules! back_to_enum {
    ($(#[$meta:meta])* $vis:vis enum $name:ident {
        $($(#[$vmeta:meta])* $vname:ident $(= $val:expr)?,)*
    }) => {
        $(#[$meta])*
        $vis enum $name {
            $($(#[$vmeta])* $vname $(= $val)?,)*
        }

        impl std::convert::TryFrom<u8> for $name {
            type Error = ();

            fn try_from(v: u8) -> Result<Self, Self::Error> {
                match v {
                    $(x if x == $name::$vname as u8 => Ok($name::$vname),)*
                    _ => Err(()),
                }
            }
        }
    }
}

back_to_enum! {
    #[derive(Debug)]
    pub enum Bytecode {
        Nop,

        LoadConstNum8,
        LoadConstNum16,
        LoadConstNum32,
        LoadConstNum64,

        LoadGlobalNum8,
        LoadGlobalNum16,
        LoadGlobalNum32,
        LoadGlobalNum64,

        StoreGlobalNum8,
        StoreGlobalNum16,
        StoreGlobalNum32,
        StoreGlobalNum64,

        LoadLocalNum8,
        LoadLocalNum16,
        LoadLocalNum32,
        LoadLocalNum64,

        StoreLocalNum8,
        StoreLocalNum16,
        StoreLocalNum32,
        StoreLocalNum64,

        AddI,
        AddU,
        AddF,

        SubI,
        SubU,
        SubF,

        MulI,
        MulU,
        MulF,

        DivI,
        DivU,
        DivF,

        And,
        Or,
        Not,

        EqI,
        EqU,
        EqF,

        EqIU,
        EqFI,
        EqFU,

        GreaterI,
        GreaterU,
        GreaterF,

        GreaterIU,
        GreaterFI,
        GreaterFU,

        LessI,
        LessU,
        LessF,

        LessIU,
        LessFI,
        LessFU,


        LoadGlobalCmplx,
        LoadLocalCmplx,

        StoreGlobalCmplx,
        StoreLocalCmplx,

        CmplxAddElement,
        CmplxRemoveElement,
        CmplxSize,
        CmplxLoadElement,
        CmplxStoreElement,

        LoadConstFunc,
        LoadGlobalFunc,
        LoadLocalFunc,

        StoreGlobalFunc,
        StoreLocalFunc,

        CallFunc,
        ReturnElement,

        Pop,
        Swap,
        Rot,

        Exit,

        LoadConstText,
        LoadGlobalText,
        LoadLocalText,

        StoreGlobalText,
        StoreLocalText,

        TextAddChar,
        TextRemoveChar,
        TextPopChar,
        TextGetSize,
        TextGetChar,

        CmplxClone,
        TextClone,

        PrintI,
        PrintU,
        PrintF,
        PrintC,
        PrintText,
        Newline,

        Cmplx2Text,

        GetInstance,

        JumpAbs,
        JumpNeg,
        JumpPos,
        JumpAbsIfTrue,
        JumpAbsIfFalse,
        JumpNegIfTrue,
        JumpNegIfFalse,
        JumpPosIfTrue,
        JumpPosIfFalse,

        ModI,
        ModU,

        CmplxBuildEmpty,
        CmplxBuildNew,

        InputI,
        InputU,
        InputF,
        InputText,
        InputLine,

        TextSetChar,
        LoadArgument,

        I2U,
        I2F,
        U2I,
        U2F,
        F2I,
        F2U,

        IsNum,
        IsText,
        IsCmplx,
        IsFunc,
        IsNothing,

        Float2Double,
        Double2Float,

        BNot,

        CmplxInit,

        I2Text,
        F2Text,
        U2Text,

        Text2I,
        Text2F,
        Text2U,

        UnaryMinusI,
        UnaryMinusF,

        TextConcat,

        InputChar,
        CallAsync,
        Clock,
        Time,

        GllLoad,
        GllSymbol,
        GllExec,
        GllClose,

        SetupIter,
        NextIter,

        TextHash,

        // Debugging
        Hint,

        // Additional Bit operator
        ShiftL,
        ShiftR,
    }
}

back_to_enum! {
    pub enum ConstantCode {
        Nop,
        Num8,
        Num16,
        Num32,
        Num64,
        Text,
        Function,
        Recover,
    }
}
