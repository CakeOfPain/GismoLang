
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define GVM_ZZE(I) ((((int64_t)I) >> 63) ^ (((int64_t)I) << 1))
#define GVM_ZZD(I) ((((int64_t)I) >> 1) ^ -(((int64_t)I) & 1))
#define GVM_U2I(X) ({uint64_t x = X;GVM_ZZE(*((int64_t*) &x)); })
#define GVM_U2F(X) ({uint64_t x = X;*((double*) &x); })
#define GVM_I2U(X) ({int64_t x = GVM_ZZD(X);*((uint64_t*) &x); })
#define GVM_I2F(X) ({int64_t x = GVM_ZZD(X);*((double*) &x); })
#define GVM_F2U(X) ({double x = X;*((uint64_t*) &x); })
#define GVM_F2I(X) ({double x = X;GVM_ZZE(*((uint64_t*) &x)); })

#define GVM_CMPLX_TAKE(V) ({ /*(V: variable of type cmplx*) -> cmplx**/\
	gvm_cmplx_t *c = V;\
	V = NULL;\
	c;\
})

#define GVM_CMPLX_ASSIGN(V, C) ({/*(V: variable of type cmplx*, C: cmplx*) -> none*/\
    gvm_clear_cmplx(V);\
    V = (gvm_cmplx_t*) C;\
})

#define GVM_CMPLX_STORE(C, I, E) ({\
	gvm_cmplx_t * c = C;\
	uint64_t i = I;\
	if(c->types[i] == GVM_TYPE_CMPLX) gvm_clear_cmplx((gvm_cmplx_t*) c->elements[i]);\
	c->elements[i] = (uint64_t) E;\
	c;\
})

typedef enum gvm_type {
	GVM_TYPE_NUM,
	GVM_TYPE_TXT,
	GVM_TYPE_CMPLX
} gvm_type_t;

typedef struct gvm_cmplx {
	uint64_t *elements;
	gvm_type_t *types;
	uint64_t number_of_elements;
	uint64_t capacity;
} gvm_cmplx_t;

gvm_cmplx_t *gvm_cmplx_create() {
	gvm_cmplx_t *c = (gvm_cmplx_t*) malloc(sizeof(gvm_cmplx_t));
	*c = (gvm_cmplx_t){.elements=NULL,.types=NULL,.number_of_elements=0,.capacity=0};
	return c;
}

gvm_cmplx_t *gvm_cmplx_add(gvm_cmplx_t *cmplx, uint64_t element, gvm_type_t type) {
	if(cmplx->number_of_elements >= cmplx->capacity) {
		cmplx->capacity = (cmplx->capacity + 1) * 2;
		cmplx->elements = (uint64_t*) realloc(cmplx->elements, cmplx->capacity * sizeof(uint64_t));
		cmplx->types    = (gvm_type_t*) realloc(cmplx->elements, cmplx->capacity * sizeof(gvm_type_t));
	}
	cmplx->elements[cmplx->number_of_elements] = element;
	cmplx->types[cmplx->number_of_elements] = type;
	++cmplx->number_of_elements;
	return cmplx;
}

uint64_t gvm_cmplx_remove(gvm_cmplx_t *cmplx, uint64_t index) {
	if(!cmplx || index >= cmplx->number_of_elements) {
		fprintf(stderr, "Accessed an array out of bounds!");
		abort();
	}
	uint64_t element = cmplx->elements[index];
	for(uint64_t i=index; i < (cmplx->number_of_elements-1); ++i) {
		cmplx->elements[i] = cmplx->elements[i+1];
	}
	--cmplx->number_of_elements;
	return element;
}

gvm_cmplx_t *gvm_clear_cmplx(gvm_cmplx_t *cmplx) {
	if(!cmplx) return NULL;
	for(uint64_t i=0; i < cmplx->number_of_elements; ++i) {
		if(cmplx->types[i] == GVM_TYPE_CMPLX) gvm_clear_cmplx((gvm_cmplx_t*) cmplx->elements[i]);
		else if(cmplx->types[i] == GVM_TYPE_TXT) free((void*) cmplx->elements[i]);
	}
	free(cmplx);
	return NULL;
}
void $function0(void); /* $function0 */
void $function1(void); /* ./libs/std.gsm:getFormatType// */
void $function2(void); /* ./libs/std.gsm:cmp/txt/txt/ */
void $function3(void); /* ./libs/std.gsm:same/txt/txt/ */
void $function4(void); /* ./libs/std.gsm:upper/txt/ */
void $function5(void); /* ./libs/std.gsm:reverse/txt/ */
void $function6(void); /* ./libs/std.gsm:pause/txt/ */
void $function7(void); /* ./libs/std.gsm:argsCheck/multi/// */
void $function8(void); /* ./libs/std.gsm:outerr/txt/ */
void $function9(void); /* ./libs/std.gsm:jErr/txt/ */
void $function10(void); /* ./libs/std.gsm:logWarning/txt/ */
void $function11(void); /* ./libs/std.gsm:abort/txt/ */
void $function12(void); /* ./libs/std.gsm:assert//txt/ */
void $function13(void); /* ./libs/std.gsm:progressbar/txt//// */
void $function14(void); /* ./libs/std.gsm:fill/txt// */
void $function15(void); /* ./libs/std.gsm:fillWith/txt/txt// */
void $function16(void); /* ./libs/std.gsm:indexOfTxtInList/multi/txt/ */
void $function17(void); /* ./libs/std.gsm:indexOfSameTxtInList/multi/txt/ */
void $function18(void); /* ./libs/std.gsm:toBytes/txt/ */
void $function19(void); /* ./libs/std.gsm:ccolor// */
void $function20(void); /* ./libs/std.gsm:isUpper// */
void $function21(void); /* ./libs/std.gsm:isLower// */
void $function22(void); /* ./libs/std.gsm:isNumeric// */
void $function23(void); /* ./libs/std.gsm:isAlpha// */
void $function24(void); /* ./libs/std.gsm:isAlphaNumeric// */
void $function25(void); /* ./libs/std.gsm:isWhitespace// */
void $function26(void); /* ./libs/std.gsm:isInText//txt/ */
void $function27(void); /* ./libs/std.gsm:filter/txt/txt/ */
void $function28(void); /* ./libs/std.gsm:insertText/txt/txt// */
void $function29(void); /* ./libs/std.gsm:subText/txt/// */
void $function30(void); /* ./libs/std.gsm:StringRepresentation/txt/ */
void $function31(void); /* ./libs/std.gsm:SQLStringRepresentation/txt/ */
void $function32(void); /* ./libs/std.gsm:getChar/txt// */
void $function33(void); /* ./libs/std.gsm:mulText/txt// */
void $function34(void); /* ./libs/std.gsm:Str/ */
void $function35(void); /* ./libs/std.gsm:getIndexInText/txt// */
void $function36(void); /* ./libs/std.gsm:stripMargin/txt/ */
void $function37(void); /* ./libs/std.gsm:makeString/multi/txt/ */
void $function38(void); /* ./libs/std.gsm:replace/txt/txt/txt/ */
void $function39(void); /* ./libs/std.gsm:countChar/txt// */
void $function40(void); /* ./libs/std.gsm:startsWith/txt/txt/ */
void $function41(void); /* ./libs/std.gsm:split/txt/txt/ */
void $function42(void); /* ./libs/std.gsm:getArgument/multi/txt/ */
void $function43(void); /* ./libs/tracer.gsm:function_tracer_enter/txt// */
void $function44(void); /* ./libs/tracer.gsm:function_tracer_leave/txt// */
void $function45(void); /* ./libs/tracer.gsm:printStackTrace/ */
void $function46(void); /* ./libs/tracer.gsm:$$GVMErrorHandler$$/ */
void $function47(void); /* ./libs/classic.gsm:dumpMemoryUse/ */
void $function48(void); /* ./libs/classic.gsm:UInt// */
void $function49(void); /* ./libs/classic.gsm:getUInt// */
void $function50(void); /* ./libs/classic.gsm:updateUInt/// */
void $function51(void); /* ./libs/classic.gsm:Int// */
void $function52(void); /* ./libs/classic.gsm:getInt// */
void $function53(void); /* ./libs/classic.gsm:updateInt/// */
void $function54(void); /* ./libs/classic.gsm:Float// */
void $function55(void); /* ./libs/classic.gsm:getFloat// */
void $function56(void); /* ./libs/classic.gsm:updateFloat/// */
void $function57(void); /* ./libs/classic.gsm:Text/txt/ */
void $function58(void); /* ./libs/classic.gsm:getText// */
void $function59(void); /* ./libs/classic.gsm:updateText//txt/ */
void $function60(void); /* ./libs/classic.gsm:ObjectNode//txt/// */
void $function61(void); /* ./libs/classic.gsm:Object/txt/ */
void $function62(void); /* ./libs/classic.gsm:classOfObject// */
void $function63(void); /* ./libs/classic.gsm:objectToText// */
void $function64(void); /* ./libs/classic.gsm:fieldsOfObject// */
void $function65(void); /* ./libs/classic.gsm:typeOfField// */
void $function66(void); /* ./libs/classic.gsm:putField//txt/// */
void $function67(void); /* ./libs/classic.gsm:getField//txt/ */
void $function68(void); /* ./libs/classic.gsm:getFieldReference//txt/ */
void $function69(void); /* ./libs/classic.gsm:getFieldValue// */
void $function70(void); /* ./libs/classic.gsm:collectByClass/txt/ */
void $function71(void); /* main.gsm:help/ */
void $function72(void); /* main.gsm:main */
void $function73(void); /* ./libs/system.gsm:isNull/txt/ */
void $function74(void); /* ./libs/system.gsm:$_getStructDescription_$/txt/ */
void $function75(void); /* ./libs/system.gsm:$_constructor_$/ */
void $function76(void); /* ./libs/system.gsm:$_selectText_$/txt/txt/ */
void $function77(void); /* ./libs/system.gsm:$_selectUInt_$/txt/txt/ */
void $function78(void); /* ./libs/system.gsm:$_selectInt_$/txt/txt/ */
void $function79(void); /* ./libs/system.gsm:$_selectFloat_$/txt/txt/ */
void $function80(void); /* ./libs/system.gsm:$_update_$/ */
void $function81(void); /* ./libs/system.gsm:drop */
void $function82(void); /* ./libs/system.gsm:classOf/txt/ */
void $function83(void); /* ./libs/system.gsm:fieldsOf/txt/ */
void $function84(void); /* ./src/GIM.gsm:GismoInstructions */
void $function85(void); /* ./src/GIM.gsm:loadGim/txt/ */
void $function86(void); /* ./src/transpiler.gsm:transpile2C/GismoInstructions/ */
void $function87(void); /* ./src/transpiler.gsm:collectConstants/GismoInstructions/ */
void $function88(void); /* ./src/transpiler.gsm:Transpile2StatementsResult */
void $function89(void); /* ./src/transpiler.gsm:transpile2Statements/txt// */
void $function90(void); /* ./libs/fs.gsm:ResultTxt */
void $function91(void); /* ./libs/fs.gsm:ResultFile */
void $function92(void); /* ./libs/fs.gsm:ResultDir */
void $function93(void); /* ./libs/fs.gsm:Path */
void $function94(void); /* ./libs/fs.gsm:Exists/Path/ */
void $function95(void); /* ./libs/fs.gsm:Type/Path/ */
void $function96(void); /* ./libs/fs.gsm:AsFile/Path/ */
void $function97(void); /* ./libs/fs.gsm:AsDir/Path/ */
void $function98(void); /* ./libs/fs.gsm:File */
void $function99(void); /* ./libs/fs.gsm:Read/File/ */
void $function100(void); /* ./libs/fs.gsm:Exists/File/ */
void $function101(void); /* ./libs/fs.gsm:Dir */
void $function102(void); /* ./libs/fs.gsm:List/Dir/ */
void $function103(void); /* ./libs/fs.gsm:Exists/Dir/ */
void $function104(void); /* ./src/byteReader.gsm:ByteReader */
void $function105(void); /* ./src/byteReader.gsm:hasNext/ByteReader/ */
void $function106(void); /* ./src/byteReader.gsm:next/ByteReader/ */
void $function107(void); /* ./src/byteReader.gsm:nextULong/ByteReader/ */
void $function108(void); /* ./src/byteReader.gsm:nextUInt/ByteReader/ */
void $function109(void); /* ./src/byteReader.gsm:nextUShort/ByteReader/ */
void $function110(void); /* ./src/byteReader.gsm:nextBuffer/ByteReader/ */
const uint8_t  const_num8[91] = {0,
0,
115,
0,
2,
4,
6,
8,
10,
12,
14,
16,
18,
20,
22,
24,
26,
28,
30,
32,
0,
1,
2,
3,
4,
5,
6,
8,
16,
246,
192,
64,
90,
65,
122,
97,
57,
48,
10,
124,
48,
12,
9,
34,
36,
38,
40,
42,
44,
46,
50,
52,
54,
56,
58,
60,
62,
66,
68,
70,
72,
74,
76,
78,
80,
82,
84,
86,
88,
90,
92,
94,
96,
98,
100,
102,
104,
106,
108,
110,
112,
114,
116,
118,
120,
122,
124,
15,
102,
100,
56,
40,
32,
24};
const uint16_t const_num16[2] = {0,
2000,
298};
const uint32_t const_num32[1] = {0,
6777197};
const uint64_t const_num64[1] = {0};
const char *const_text[371] = {"undefined",
"none",
"ubyte",
"byte",
"ushort",
"short",
"uint",
"int",
"float",
"ulong",
"long",
"double",
"text",
"function",
"Collection",
"complex",
"any",
"\n",
" \n\t",
"1234567890",
"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
"abcdefghijklmnopqrstuvwxyz",
"",
"Too few arguments . . .",
"Too many arguments . . .",
"Full stack trace: ",
"\r \r",
"[",
"#",
" ",
"]",
"\"",
"\\\"",
"\\",
"\\\\",
"\\n",
"\t",
"\\t",
"\a",
"\\a",
"\r",
"\\r",
"\b",
"\\b",
"0",
"\"\"",
"Wrong Datatype",
"=",
"\027[0;31m",
"Error = Too many function calls. Recursion calls?",
"\027[0m",
"----------------Traced-Functions----------------",
"If Functioncall Stack is empty, you might want to enable debbuging mode",
"Use instead of 'run' and 'build' the prefix 'debug='",
"...",
" - Function Call At Line ",
": ",
"------------------------------------------------",
"[NIL]",
"Memory used: \n",
"\tuint[",
"] = ",
" bytes \n",
"\tint[",
"\tfloat[",
"\ttxt[",
"\tObject[",
"\tObjNode[",
"{",
"}",
"Nop",
"LoadConstNum8",
"LoadConstNum16",
"LoadConstNum32",
"LoadConstNum64",
"LoadGlobalNum8",
"LoadGlobalNum16",
"LoadGlobalNum32",
"LoadGlobalNum64",
"StoreGlobalNum8",
"StoreGlobalNum16",
"StoreGlobalNum32",
"StoreGlobalNum64",
"LoadLocalNum8",
"LoadLocalNum16",
"LoadLocalNum32",
"LoadLocalNum64",
"StoreLocalNum8",
"StoreLocalNum16",
"StoreLocalNum32",
"StoreLocalNum64",
"AddI",
"AddU",
"AddF",
"SubI",
"SubU",
"SubF",
"MulI",
"MulU",
"MulF",
"DivI",
"DivU",
"DivF",
"And",
"Or",
"Not",
"EqI",
"EqU",
"EqF",
"EqIU",
"EqFI",
"EqFU",
"GreaterI",
"GreaterU",
"GreaterF",
"GreaterIU",
"GreaterFI",
"GreaterFU",
"LessI",
"LessU",
"LessF",
"LessIU",
"LessFI",
"LessFU",
"LoadGlobalCmplx",
"LoadLocalCmplx",
"StoreGlobalCmplx",
"StoreLocalCmplx",
"CmplxAddElement",
"CmplxRemoveElement",
"CmplxSize",
"CmplxLoadElement",
"CmplxStoreElement",
"LoadConstFunc",
"LoadGlobalFunc",
"LoadLocalFunc",
"StoreGlobalFunc",
"StoreLocalFunc",
"CallFunc",
"ReturnElement",
"Pop",
"Swap",
"Rot",
"Exit",
"LoadConstText",
"LoadGlobalText",
"LoadLocalText",
"StoreGlobalText",
"StoreLocalText",
"TextAddChar",
"TextRemoveChar",
"TextPopChar",
"TextGetSize",
"TextGetChar",
"CmplxClone",
"TextClone",
"PrintI",
"PrintU",
"PrintF",
"PrintC",
"PrintText",
"Newline",
"Cmplx2Text",
"GetInstance",
"JumpAbs",
"JumpNeg",
"JumpPos",
"JumpAbsIfTrue",
"JumpAbsIfFalse",
"JumpNegIfTrue",
"JumpNegIfFalse",
"JumpPosIfTrue",
"JumpPosIfFalse",
"ModI",
"ModU",
"CmplxBuildEmpty",
"CmplxBuildNew",
"InputI",
"InputU",
"InputF",
"InputText",
"InputLine",
"TextSetChar",
"LoadArgument",
"I2U",
"I2F",
"U2I",
"U2F",
"F2I",
"F2U",
"IsNum",
"IsText",
"IsCmplx",
"IsFunc",
"IsNothing",
"Float2Double",
"Double2Float",
"BNot",
"CmplxInit",
"I2Text",
"F2Text",
"U2Text",
"Text2I",
"Text2F",
"Text2U",
"UnaryMinusI",
"UnaryMinusF",
"TextConcat",
"InputChar",
"CallAsync",
"Clock",
"Time",
"GllLoad",
"GllSymbol",
"GllExec",
"GnlClose",
"SetupIter",
"NextIter",
"TextHash",
"Hint",
"ShiftL",
"ShiftR",
"G2.9",
"fetch",
"Gismo Bytecode Transpiler",
"Arguments-Usage:",
"*source\tpath to your .gim file to translate",
"Arguments marked with a * are not optional",
"source",
"Required argument source is missing!",
"(",
",",
":",
"Field isn't a valid formatType!",
"GismoInstructions(constNum8Size:uint,constNum16Size:uint,constNum32Size:uint,constNum64Size:uint,constFuncSize:uint,constTextSize:uint,globalNum8Size:uint,globalNum16Size:uint,globalNum32Size:uint,globalNum64Size:uint,globalFuncSize:uint,globalTextSize:uint,globalCmplxSize:uint,bytecode:text)",
"error",
"content",
"Transpiler Error: Not valid file format",
"\n#include <stdio.h>\n#include <stdint.h>\n#include <stdlib.h>\n\n#define GVM_ZZE(I) ((((int64_t)I) >> 63) ^ (((int64_t)I) << 1))\n#define GVM_ZZD(I) ((((int64_t)I) >> 1) ^ -(((int64_t)I) & 1))\n#define GVM_U2I(X) ({uint64_t x = X;GVM_ZZE(*((int64_t*) &x)); })\n#define GVM_U2F(X) ({uint64_t x = X;*((double*) &x); })\n#define GVM_I2U(X) ({int64_t x = GVM_ZZD(X);*((uint64_t*) &x); })\n#define GVM_I2F(X) ({int64_t x = GVM_ZZD(X);*((double*) &x); })\n#define GVM_F2U(X) ({double x = X;*((uint64_t*) &x); })\n#define GVM_F2I(X) ({double x = X;GVM_ZZE(*((uint64_t*) &x)); })\n\n#define GVM_CMPLX_TAKE(V) ({ /*(V: variable of type cmplx*) -> cmplx**/\\\n\tgvm_cmplx_t *c = V;\\\n\tV = NULL;\\\n\tc;\\\n})\n\n#define GVM_CMPLX_ASSIGN(V, C) ({/*(V: variable of type cmplx*, C: cmplx*) -> none*/\\\n    gvm_clear_cmplx(V);\\\n    V = (gvm_cmplx_t*) C;\\\n})\n\n#define GVM_CMPLX_STORE(C, I, E) ({\\\n\tgvm_cmplx_t * c = C;\\\n\tuint64_t i = I;\\\n\tif(c->types[i] == GVM_TYPE_CMPLX) gvm_clear_cmplx((gvm_cmplx_t*) c->elements[i]);\\\n\tc->elements[i] = (uint64_t) E;\\\n\tc;\\\n})\n\ntypedef enum gvm_type {\n\tGVM_TYPE_NUM,\n\tGVM_TYPE_TXT,\n\tGVM_TYPE_CMPLX\n} gvm_type_t;\n\ntypedef struct gvm_cmplx {\n\tuint64_t *elements;\n\tgvm_type_t *types;\n\tuint64_t number_of_elements;\n\tuint64_t capacity;\n} gvm_cmplx_t;\n\ngvm_cmplx_t *gvm_cmplx_create() {\n\tgvm_cmplx_t *c = (gvm_cmplx_t*) malloc(sizeof(gvm_cmplx_t));\n\t*c = (gvm_cmplx_t){.elements=NULL,.types=NULL,.number_of_elements=0,.capacity=0};\n\treturn c;\n}\n\ngvm_cmplx_t *gvm_cmplx_add(gvm_cmplx_t *cmplx, uint64_t element, gvm_type_t type) {\n\tif(cmplx->number_of_elements >= cmplx->capacity) {\n\t\tcmplx->capacity = (cmplx->capacity + 1) * 2;\n\t\tcmplx->elements = (uint64_t*) realloc(cmplx->elements, cmplx->capacity * sizeof(uint64_t));\n\t\tcmplx->types    = (gvm_type_t*) realloc(cmplx->elements, cmplx->capacity * sizeof(gvm_type_t));\n\t}\n\tcmplx->elements[cmplx->number_of_elements] = element;\n\tcmplx->types[cmplx->number_of_elements] = type;\n\t++cmplx->number_of_elements;\n\treturn cmplx;\n}\n\nuint64_t gvm_cmplx_remove(gvm_cmplx_t *cmplx, uint64_t index) {\n\tif(!cmplx || index >= cmplx->number_of_elements) {\n\t\tfprintf(stderr, \"Accessed an array out of bounds!\");\n\t\tabort();\n\t}\n\tuint64_t element = cmplx->elements[index];\n\tfor(uint64_t i=index; i < (cmplx->number_of_elements-1); ++i) {\n\t\tcmplx->elements[i] = cmplx->elements[i+1];\n\t}\n\t--cmplx->number_of_elements;\n\treturn element;\n}\n\ngvm_cmplx_t *gvm_clear_cmplx(gvm_cmplx_t *cmplx) {\n\tif(!cmplx) return NULL;\n\tfor(uint64_t i=0; i < cmplx->number_of_elements; ++i) {\n\t\tif(cmplx->types[i] == GVM_TYPE_CMPLX) gvm_clear_cmplx((gvm_cmplx_t*) cmplx->elements[i]);\n\t\telse if(cmplx->types[i] == GVM_TYPE_TXT) free((void*) cmplx->elements[i]);\n\t}\n\tfree(cmplx);\n\treturn NULL;\n}\n",
"bytecode",
"statements",
"functionName",
" */",
"*",
"multi",
"(void); /* ",
"$function",
"void ",
"(void) {/* ",
"\tuint8_t local_num8[",
"] = {0};\n",
"\tuint16_t local_num16[",
"\tuint32_t local_num32[",
"\tuint64_t local_num64[",
"\tchar *local_text[",
"] = {NULL};\n",
"\tvoid *local_func[",
"\tgvm_cmplx_t *local_cmplx[",
"] = {NULL};\n\t",
"\n}",
"};\n",
",\n",
"] = {",
"constNum8Size",
"const uint8_t  const_num8[",
"constNum16Size",
"const uint16_t const_num16[",
"constNum32Size",
"const uint32_t const_num32[",
"constNum64Size",
"const uint64_t const_num64[",
"constTextSize",
"const char *const_text[",
"globalNum8Size",
"uint8_t global_num8[",
"globalNum16Size",
"uint16_t global_num16[",
"globalNum32Size",
"uint32_t global_num32[",
"globalNum64Size",
"uint64_t global_num64[",
"globalTextSize",
"char *global_text[",
"globalFuncSize",
"void *global_func[",
"] = {NULL};\n\n",
"globalCmplxSize",
"gvm_cmplx_t *global_cmplx[",
"Transpile2StatementsResult(statements:text,functionName:text)",
"const_num8[",
"const_num16[",
"const_num32[",
"const_num64[",
"global_num8[",
"global_num16[",
"global_num32[",
"global_num64[",
";",
"local_num8[",
"local_num16[",
"local_num32[",
"local_num64[",
")))",
") + GVM_U2I(",
"(GVM_I2U(GVM_U2I(",
")",
" + ",
") + GVM_U2F(",
"(GVM_F2U(GVM_U2F(",
") - GVM_U2I(",
" - ",
") - GVM_U2F(",
") * GVM_U2I(",
" * ",
") * GVM_U2F(",
") / GVM_U2I(",
" / ",
") / GVM_U2F(",
" & ",
" | ",
"(!",
"))",
") == GVM_U2I(",
"(GVM_U2I(",
" == ",
") == GVM_U2F(",
"(GVM_U2F(",
") == ",
") < GVM_U2I(",
" < ",
") < GVM_U2F(",
") < ",
") > GVM_U2I(",
" > ",
") > GVM_U2F(",
") > ",
"(GVM_CMPLX_TAKE(global_cmplx[",
"]))",
"(GVM_CMPLX_TAKE(local_cmplx[",
"GVM_CMPLX_ASSIGN(global_cmplx[",
"], ",
");",
"GVM_CMPLX_ASSIGN(local_cmplx[",
"(gvm_cmplx_add(",
", ((uint64_t)",
"), ",
"(gvm_cmplx_remove(",
"->number_of_elements)",
"->elements[",
"])",
"(GVM_CMPLX_STORE(",
", ",
"fl",
"*/",
"/*WARNING: Incomplete Instruction Set Translation for ",
"\n\t",
"ResultTxt(content:text,error:text)",
"ResultFile(file:text,error:text)",
"ResultDir(dir:text,error:text)",
"Path(path:text)",
"path",
" is not a file or does not exist",
"File Error: ",
" is not a directory or does not exist",
"Directory Error: ",
"File(path:text)",
"Dir(path:text)",
" is not a dir or does not exist",
"ByteReader(buffer:text,count:uint)",
"buffer",
"count"};

uint8_t global_num8[27] = {0};
uint16_t global_num16[3] = {0};
uint32_t global_num32[0] = {0};
uint64_t global_num64[0] = {0};
char *global_text[8] = {NULL};
void *global_func[0] = {NULL};
gvm_cmplx_t *global_cmplx[15] = {NULL};

void $function0(void) {/* $function0 */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	global_num8[0] = const_num8[0];
	global_num8[1] = const_num8[1];
	global_num8[2] = const_num8[2];
	global_num8[3] = const_num8[3];
	global_num8[4] = const_num8[4];
	global_num8[5] = const_num8[5];
	global_num8[6] = const_num8[6];
	global_num8[7] = const_num8[7];
	global_num8[8] = const_num8[8];
	global_num8[9] = const_num8[9];
	global_num8[10] = const_num8[10];
	global_num8[11] = const_num8[11];
	global_num8[12] = const_num8[12];
	global_num8[13] = const_num8[13];
	global_num8[14] = const_num8[14];
	global_num8[15] = const_num8[15];
	global_num8[16] = const_num8[16];
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalText*/
	global_num8[17] = const_num8[17];
	global_num8[18] = const_num8[18];
	global_num8[19] = const_num8[19];
	global_num8[20] = const_num8[20];
	global_num8[21] = const_num8[21];
	global_num8[22] = const_num8[22];
	global_num8[23] = const_num8[23];
	global_num8[24] = const_num8[24];
	global_num8[25] = const_num8[25];
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadGlobalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadGlobalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalCmplx*/
	global_num16[0] = const_num16[0];
	global_num8[26] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], const_num8[17]);
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], const_num8[0]);
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], const_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], const_num8[17]);
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[9], const_num8[17]);
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[10], const_num8[17]);
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[12], const_num8[17]);
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for UnaryMinusI*/
	/*WARNING: Incomplete Instruction Set Translation for UnaryMinusI*/
	GVM_CMPLX_ASSIGN(global_cmplx[14], (gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add((gvm_cmplx_add(const_num8[0], ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[2]), 0)), ((uint64_t)const_num8[2]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[2]), 0)), ((uint64_t)const_num8[2]), 0)), ((uint64_t)const_num8[2]), 0)), ((uint64_t)const_num8[2]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[1]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[4]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[1]), 0)), ((uint64_t)const_num8[0]), 0)), ((uint64_t)const_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalText*/
	/*WARNING: Incomplete Instruction Set Translation for GllLoad*/
	/*WARNING: Incomplete Instruction Set Translation for StoreGlobalNum16*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for GllSymbol*/
	global_num16[2] = global_num16[1];
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxClone*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
}
void $function1(void) {/* ./libs/std.gsm:getFormatType// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function2(void) {/* ./libs/std.gsm:cmp/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[1] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for EqU*/
	/*WARNING: Incomplete Instruction Set Translation for Not*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	local_num32[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	local_num32[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num32[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function3(void) {/* ./libs/std.gsm:same/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[1] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for EqU*/
	/*WARNING: Incomplete Instruction Set Translation for Not*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	local_num32[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	local_num32[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num32[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function4(void) {/* ./libs/std.gsm:upper/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	local_num64[1] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	local_num64[1] = (GVM_I2U(GVM_U2I(const_num8[28]) - GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for TextRemoveChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function5(void) {/* ./libs/std.gsm:reverse/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[1];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessIU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for TextRemoveChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function6(void) {/* ./libs/std.gsm:pause/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for InputChar*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadGlobalText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
}
void $function7(void) {/* ./libs/std.gsm:argsCheck/multi/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[3] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
}
void $function8(void) {/* ./libs/std.gsm:outerr/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
}
void $function9(void) {/* ./libs/std.gsm:jErr/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for Exit*/
}
void $function10(void) {/* ./libs/std.gsm:logWarning/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
}
void $function11(void) {/* ./libs/std.gsm:abort/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
}
void $function12(void) {/* ./libs/std.gsm:assert//txt/ */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum8*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
}
void $function13(void) {/* ./libs/std.gsm:progressbar/txt//// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[6] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	local_num64[3] = (GVM_F2U(GVM_U2F(global_num64[1]) / GVM_U2F(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for I2F*/
	/*WARNING: Incomplete Instruction Set Translation for F2I*/
	local_num64[4] = (GVM_F2U(GVM_U2F(global_num64[2]) * GVM_U2F(global_num64[3])));
	local_num64[5] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for GreaterIU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	local_num64[5] = (const_num8[18] + global_num64[5]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	local_num64[5] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	local_num64[5] = (const_num8[18] + global_num64[5]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	local_num64[5] = (const_num8[18] + global_num64[5]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
}
void $function14(void) {/* ./libs/std.gsm:fill/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function15(void) {/* ./libs/std.gsm:fillWith/txt/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	local_num64[1] = (GVM_U2I((GVM_I2U(GVM_U2I(const_num8[18]) + GVM_U2I(global_num64[0])))) < (GVM_U2I(const_num8[0]) > GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[1] = (const_num8[18] + global_num64[1]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for UnaryMinusI*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) * GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	local_num64[1] = (GVM_U2I((GVM_I2U(GVM_U2I(const_num8[18]) + GVM_U2I(global_num64[0])))) < (GVM_U2I((GVM_I2U(GVM_U2I(const_num8[18]) + GVM_U2I(global_num64[0])))) < global_num64[1]));
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[1] = (const_num8[18] + global_num64[1]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function16(void) {/* ./libs/std.gsm:indexOfTxtInList/multi/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[17];
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for LessU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for UnaryMinusI*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function17(void) {/* ./libs/std.gsm:indexOfSameTxtInList/multi/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[17];
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for LessU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for UnaryMinusI*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function18(void) {/* ./libs/std.gsm:toBytes/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	local_num64[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessIU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[0])), ((uint64_t)global_num64[0]), 0)));
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function19(void) {/* ./libs/std.gsm:ccolor// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[1] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum16*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function20(void) {/* ./libs/std.gsm:isUpper// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum8*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function21(void) {/* ./libs/std.gsm:isLower// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum8*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function22(void) {/* ./libs/std.gsm:isNumeric// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum8*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function23(void) {/* ./libs/std.gsm:isAlpha// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum8*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function24(void) {/* ./libs/std.gsm:isAlphaNumeric// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum8*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function25(void) {/* ./libs/std.gsm:isWhitespace// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum8*/
	/*WARNING: Incomplete Instruction Set Translation for LoadGlobalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function26(void) {/* ./libs/std.gsm:isInText//txt/ */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum8*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessIU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function27(void) {/* ./libs/std.gsm:filter/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[3] = {0};
	char *local_text[3] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessIU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	local_num64[2] = global_num64[0];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function28(void) {/* ./libs/std.gsm:insertText/txt/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[3] = {0};
	char *local_text[3] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[1] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for And*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[1] = (const_num8[18] + global_num64[1]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	local_num64[2] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[2] = (const_num8[18] + global_num64[2]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[1] = (const_num8[18] + global_num64[1]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function29(void) {/* ./libs/std.gsm:subText/txt/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[3] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[2] = global_num64[0];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[2] = (const_num8[18] + global_num64[2]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function30(void) {/* ./libs/std.gsm:StringRepresentation/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = (const_num8[18] + global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function31(void) {/* ./libs/std.gsm:SQLStringRepresentation/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = (const_num8[18] + global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function32(void) {/* ./libs/std.gsm:getChar/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function33(void) {/* ./libs/std.gsm:mulText/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[1] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[1] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function34(void) {/* ./libs/std.gsm:Str/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[2] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	local_num64[0] = const_num8[17];
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for LessU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for And*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = (const_num8[18] + global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function35(void) {/* ./libs/std.gsm:getIndexInText/txt// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum8*/
	local_num64[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessIU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for UnaryMinusI*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function36(void) {/* ./libs/std.gsm:stripMargin/txt/ */
	uint8_t local_num8[2] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	local_num8[1] = global_num64[0];
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	local_num8[1] = global_num64[0];
	local_num64[0] = (const_num8[18] + global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	local_num64[0] = (const_num8[18] - global_num64[0]);
	local_num64[0] = (const_num8[18] + global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function37(void) {/* ./libs/std.gsm:makeString/multi/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[17];
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for LessU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = (const_num8[18] + global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function38(void) {/* ./libs/std.gsm:replace/txt/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[4] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[1];
	local_num64[1] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessIU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[1];
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	local_num64[0] = global_num64[1];
	local_num64[1] = (GVM_I2U(GVM_U2I(global_num64[0]) + GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function39(void) {/* ./libs/std.gsm:countChar/txt// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum8*/
	local_num64[0] = const_num8[0];
	local_num64[1] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessIU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	local_num64[1] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function40(void) {/* ./libs/std.gsm:startsWith/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function41(void) {/* ./libs/std.gsm:split/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[3] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessIU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add(global_num64[0], ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[0]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	local_num64[0] = (GVM_I2U(GVM_U2I((GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[0])))) + GVM_U2I((GVM_I2U(GVM_U2I(global_num64[0]) + GVM_U2I(global_num64[0]))))));
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add(global_num64[0], ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[0]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function42(void) {/* ./libs/std.gsm:getArgument/multi/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[4] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[0];
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for LessIU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function43(void) {/* ./libs/tracer.gsm:function_tracer_enter/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	global_num8[26] = const_num8[18];
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Exit*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], (gvm_cmplx_add(const_num8[1], ((uint64_t)(GVM_CMPLX_TAKE(global_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(global_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[2])), ((uint64_t)global_num64[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function44(void) {/* ./libs/tracer.gsm:function_tracer_leave/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for LessU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->number_of_elements));
	local_num64[1] = (const_num8[18] - const_num8[17]);
	GVM_CMPLX_ASSIGN(global_cmplx[1], const_num8[18]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	GVM_CMPLX_ASSIGN(global_cmplx[2], const_num8[18]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function45(void) {/* ./libs/tracer.gsm:printStackTrace/ */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[5] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	local_num64[0] = const_num8[17];
	local_num8[0] = const_num8[17];
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for EqU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	GVM_CMPLX_ASSIGN(global_cmplx[2], ((GVM_CMPLX_TAKE(global_cmplx[2]))->number_of_elements));
	local_num64[1] = (const_num8[18] - const_num8[17]);
	GVM_CMPLX_ASSIGN(global_cmplx[1], const_num8[18]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	GVM_CMPLX_ASSIGN(global_cmplx[2], const_num8[18]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	local_num64[2] = const_num8[17];
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->number_of_elements));
	local_num64[4] = (const_num8[18] - (gvm_cmplx_remove((GVM_CMPLX_TAKE(global_cmplx[2])), ((uint64_t)global_num64[1]))));
	GVM_CMPLX_ASSIGN(global_cmplx[2], ((GVM_CMPLX_TAKE(global_cmplx[2]))->elements[global_num64[4]]));
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	local_num8[0] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintU*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	GVM_CMPLX_ASSIGN(global_cmplx[2], ((GVM_CMPLX_TAKE(global_cmplx[2]))->elements[global_num64[4]]));
	/*WARNING: Incomplete Instruction Set Translation for PrintU*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->elements[global_num64[4]]));
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	local_num8[0] = const_num8[18];
	GVM_CMPLX_ASSIGN(global_cmplx[2], ((GVM_CMPLX_TAKE(global_cmplx[2]))->elements[global_num64[4]]));
	local_num64[0] = (!global_num8[0]);
	GVM_CMPLX_ASSIGN(global_cmplx[2], global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	local_num64[2] = (const_num8[18] + global_num64[2]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
}
void $function46(void) {/* ./libs/tracer.gsm:$$GVMErrorHandler$$/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
}
void $function47(void) {/* ./libs/classic.gsm:dumpMemoryUse/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[4] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], ((GVM_CMPLX_TAKE(global_cmplx[3]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], ((GVM_CMPLX_TAKE(global_cmplx[3]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for MulI*/
	/*WARNING: Incomplete Instruction Set Translation for I2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], ((GVM_CMPLX_TAKE(global_cmplx[4]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], ((GVM_CMPLX_TAKE(global_cmplx[4]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], ((GVM_CMPLX_TAKE(global_cmplx[5]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], ((GVM_CMPLX_TAKE(global_cmplx[5]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(global_cmplx[6], ((GVM_CMPLX_TAKE(global_cmplx[6]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	local_num64[0] = const_num8[0];
	local_num64[1] = const_num8[0];
	GVM_CMPLX_ASSIGN(global_cmplx[6], ((GVM_CMPLX_TAKE(global_cmplx[6]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(global_cmplx[6], ((GVM_CMPLX_TAKE(global_cmplx[6]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	local_num64[0] = (GVM_I2U(GVM_U2I(global_num64[0]) + GVM_U2I((GVM_U2I(global_num64[1]) > (GVM_I2U(GVM_U2I(const_num8[8]) * GVM_U2I((GVM_I2U(GVM_U2I(const_num8[8]) * GVM_U2I(const_num8[8]))))))))));
	local_num64[1] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for I2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(global_cmplx[12], ((GVM_CMPLX_TAKE(global_cmplx[12]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	local_num64[2] = const_num8[8];
	local_num64[1] = const_num8[0];
	GVM_CMPLX_ASSIGN(global_cmplx[12], ((GVM_CMPLX_TAKE(global_cmplx[12]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(global_cmplx[11], ((GVM_CMPLX_TAKE(global_cmplx[11]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	local_num64[2] = (GVM_I2U(GVM_U2I(global_num64[2]) + GVM_U2I((GVM_U2I(global_num64[1]) > global_num64[0]))));
	local_num64[1] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for I2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	local_num64[3] = const_num8[37];
	local_num64[1] = const_num8[0];
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	local_num64[3] = (GVM_I2U(GVM_U2I(global_num64[3]) + GVM_U2I((GVM_U2I(global_num64[1]) > global_num64[2]))));
	local_num64[1] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for I2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function48(void) {/* ./libs/classic.gsm:UInt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], ((GVM_CMPLX_TAKE(global_cmplx[3]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[3])), ((uint64_t)global_num64[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function49(void) {/* ./libs/classic.gsm:getUInt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], ((GVM_CMPLX_TAKE(global_cmplx[3]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function50(void) {/* ./libs/classic.gsm:updateUInt/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], (GVM_CMPLX_STORE(global_num64[0], global_num64[1], (GVM_CMPLX_TAKE(global_cmplx[3])))));
}
void $function51(void) {/* ./libs/classic.gsm:Int// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], ((GVM_CMPLX_TAKE(global_cmplx[4]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[4])), ((uint64_t)global_num64[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function52(void) {/* ./libs/classic.gsm:getInt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], ((GVM_CMPLX_TAKE(global_cmplx[4]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function53(void) {/* ./libs/classic.gsm:updateInt/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], (GVM_CMPLX_STORE(global_num64[0], global_num64[1], (GVM_CMPLX_TAKE(global_cmplx[4])))));
}
void $function54(void) {/* ./libs/classic.gsm:Float// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], ((GVM_CMPLX_TAKE(global_cmplx[5]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[5])), ((uint64_t)global_num64[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function55(void) {/* ./libs/classic.gsm:getFloat// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], ((GVM_CMPLX_TAKE(global_cmplx[5]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function56(void) {/* ./libs/classic.gsm:updateFloat/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], (GVM_CMPLX_STORE(global_num64[0], global_num64[1], (GVM_CMPLX_TAKE(global_cmplx[5])))));
}
void $function57(void) {/* ./libs/classic.gsm:Text/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	GVM_CMPLX_ASSIGN(global_cmplx[6], ((GVM_CMPLX_TAKE(global_cmplx[6]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[6], (GVM_CMPLX_TAKE(global_cmplx[6])));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function58(void) {/* ./libs/classic.gsm:getText// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[6], ((GVM_CMPLX_TAKE(global_cmplx[6]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function59(void) {/* ./libs/classic.gsm:updateText//txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxStoreElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[6], global_num64[0]);
}
void $function60(void) {/* ./libs/classic.gsm:ObjectNode//txt/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[4] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[7])), ((uint64_t)global_num64[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], (GVM_CMPLX_TAKE(global_cmplx[8])));
	GVM_CMPLX_ASSIGN(global_cmplx[9], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[9])), ((uint64_t)global_num64[1]), 0)));
	GVM_CMPLX_ASSIGN(global_cmplx[10], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[10])), ((uint64_t)global_num64[2]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function61(void) {/* ./libs/classic.gsm:Object/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	GVM_CMPLX_ASSIGN(global_cmplx[11], ((GVM_CMPLX_TAKE(global_cmplx[11]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[11], (GVM_CMPLX_TAKE(global_cmplx[11])));
	GVM_CMPLX_ASSIGN(global_cmplx[12], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[12])), ((uint64_t)const_num8[17]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function62(void) {/* ./libs/classic.gsm:classOfObject// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[11], ((GVM_CMPLX_TAKE(global_cmplx[11]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function63(void) {/* ./libs/classic.gsm:objectToText// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function64(void) {/* ./libs/classic.gsm:fieldsOfObject// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[12], ((GVM_CMPLX_TAKE(global_cmplx[12]))->elements[global_num64[0]]));
	local_num64[1] = (GVM_CMPLX_TAKE(local_cmplx[0]));
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((!(const_num8[17] == (const_num8[17] == global_num64[0]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[0]))), 4)));
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((!(const_num8[17] == global_num64[1])), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[0]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function65(void) {/* ./libs/classic.gsm:typeOfField// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[10], ((GVM_CMPLX_TAKE(global_cmplx[10]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function66(void) {/* ./libs/classic.gsm:putField//txt/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[5] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	local_num64[3] = global_num64[2];
	GVM_CMPLX_ASSIGN(global_cmplx[12], ((GVM_CMPLX_TAKE(global_cmplx[12]))->elements[global_num64[0]]));
	local_num64[4] = global_num64[1];
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(global_cmplx[12], (GVM_CMPLX_STORE(global_num64[0], global_num64[3], (GVM_CMPLX_TAKE(global_cmplx[12])))));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[4]]));
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[4]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[4]]));
	local_num64[4] = ((!(!(const_num8[17] == const_num8[18]))) & (const_num8[17] == global_num64[4]));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[4]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], (GVM_CMPLX_STORE(global_num64[4], global_num64[3], (GVM_CMPLX_TAKE(global_cmplx[7])))));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(global_cmplx[9], (GVM_CMPLX_STORE(global_num64[4], global_num64[1], (GVM_CMPLX_TAKE(global_cmplx[9])))));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function67(void) {/* ./libs/classic.gsm:getField//txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[12], ((GVM_CMPLX_TAKE(global_cmplx[12]))->elements[global_num64[0]]));
	local_num64[1] = const_num8[17];
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	GVM_CMPLX_ASSIGN(global_cmplx[9], ((GVM_CMPLX_TAKE(global_cmplx[9]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[1]]));
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for And*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[1]]));
	local_num64[1] = (!(!(const_num8[17] == ((!(const_num8[17] == global_num64[1])) & (const_num8[17] == global_num64[0])))));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Not*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[9], ((GVM_CMPLX_TAKE(global_cmplx[9]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function68(void) {/* ./libs/classic.gsm:getFieldReference//txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[12], ((GVM_CMPLX_TAKE(global_cmplx[12]))->elements[global_num64[0]]));
	local_num64[1] = const_num8[17];
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[1]]));
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[1]]));
	local_num64[1] = ((!(!(const_num8[17] == global_num64[1]))) & ((!(const_num8[17] == global_num64[1])) & (const_num8[17] == global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Not*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function69(void) {/* ./libs/classic.gsm:getFieldValue// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(global_cmplx[9], ((GVM_CMPLX_TAKE(global_cmplx[9]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function70(void) {/* ./libs/classic.gsm:collectByClass/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[3] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	local_num64[0] = const_num8[0];
	GVM_CMPLX_ASSIGN(global_cmplx[11], ((GVM_CMPLX_TAKE(global_cmplx[11]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for LessIU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(global_cmplx[11], ((GVM_CMPLX_TAKE(global_cmplx[11]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[0])), ((uint64_t)global_num64[0]), 0)));
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function71(void) {/* main.gsm:help/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
	/*WARNING: Incomplete Instruction Set Translation for Exit*/
}
void $function72(void) {/* main.gsm:main */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[3] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for GreaterIU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxClone*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (GVM_CMPLX_TAKE(local_cmplx[0])));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for PrintText*/
	/*WARNING: Incomplete Instruction Set Translation for Newline*/
}
void $function73(void) {/* ./libs/system.gsm:isNull/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for LoadGlobalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for EqU*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function74(void) {/* ./libs/system.gsm:$_getStructDescription_$/txt/ */
	uint8_t local_num8[2] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	local_num8[1] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextRemoveChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for JumpAbs*/
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for TextRemoveChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function75(void) {/* ./libs/system.gsm:$_constructor_$/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[4] = {0};
	char *local_text[4] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[5] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[17]]));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	local_num64[1] = const_num8[18];
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for LessU*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], ((GVM_CMPLX_TAKE(local_cmplx[2]))->elements[(const_num8[18] - global_num64[1])]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	GVM_CMPLX_ASSIGN(local_cmplx[4], global_num64[1]);
	GVM_CMPLX_ASSIGN(local_cmplx[4], ((GVM_CMPLX_TAKE(local_cmplx[4]))->elements[const_num8[17]]));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	local_num64[1] = (const_num8[18] + global_num64[1]);
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function76(void) {/* ./libs/system.gsm:$_selectText_$/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for Text2U*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function77(void) {/* ./libs/system.gsm:$_selectUInt_$/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for Text2U*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function78(void) {/* ./libs/system.gsm:$_selectInt_$/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for Text2U*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function79(void) {/* ./libs/system.gsm:$_selectFloat_$/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for Text2U*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function80(void) {/* ./libs/system.gsm:$_update_$/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[2] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[17]]));
	/*WARNING: Incomplete Instruction Set Translation for Text2U*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[18]]));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->elements[const_num8[19]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[19]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[19]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[19]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[19]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[19]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
}
void $function81(void) {/* ./libs/system.gsm:drop */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
}
void $function82(void) {/* ./libs/system.gsm:classOf/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for Text2U*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function83(void) {/* ./libs/system.gsm:fieldsOf/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for Text2U*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function84(void) {/* ./src/GIM.gsm:GismoInstructions */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[13] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function85(void) {/* ./src/GIM.gsm:loadGim/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[14] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[5] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	local_num32[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	local_num32[1] = (!(const_num32[0] == global_num32[0]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function86(void) {/* ./src/transpiler.gsm:transpile2C/GismoInstructions/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function87(void) {/* ./src/transpiler.gsm:collectConstants/GismoInstructions/ */
	uint8_t local_num8[2] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[14] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[11] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[7] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], const_num8[0]);
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	local_num64[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum8*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	local_num32[7] = ((GVM_U2I(const_num8[7]) == global_num8[1]) | (GVM_U2I(const_num8[6]) == global_num8[1]));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	local_num32[8] = (GVM_U2I(const_num8[5]) == global_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	local_num32[9] = (GVM_U2I(const_num8[4]) == global_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	local_num32[10] = (GVM_U2I(const_num8[3]) == global_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	local_num32[11] = (GVM_U2I(const_num8[2]) == global_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	local_num32[12] = (GVM_U2I(const_num8[1]) == global_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	local_num32[13] = (GVM_U2I(const_num8[0]) == global_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[5], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[5])), ((uint64_t)global_num64[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[6], (gvm_cmplx_add(global_num32[11], ((uint64_t)global_num32[13]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	GVM_CMPLX_ASSIGN(local_cmplx[4], (gvm_cmplx_add(global_num32[12], ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[4]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	GVM_CMPLX_ASSIGN(local_cmplx[3], (gvm_cmplx_add(global_num32[10], ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[3]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add(global_num32[9], ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[2]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add(global_num32[8], ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add(global_num32[7], ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[0]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxClone*/
	GVM_CMPLX_ASSIGN(local_cmplx[5], (GVM_CMPLX_TAKE(local_cmplx[5])));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxClone*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (GVM_CMPLX_TAKE(local_cmplx[0])));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxClone*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (GVM_CMPLX_TAKE(local_cmplx[1])));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxClone*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], (GVM_CMPLX_TAKE(local_cmplx[2])));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxClone*/
	GVM_CMPLX_ASSIGN(local_cmplx[3], (GVM_CMPLX_TAKE(local_cmplx[3])));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxClone*/
	GVM_CMPLX_ASSIGN(local_cmplx[4], (GVM_CMPLX_TAKE(local_cmplx[4])));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxClone*/
	GVM_CMPLX_ASSIGN(local_cmplx[6], (GVM_CMPLX_TAKE(local_cmplx[6])));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function88(void) {/* ./src/transpiler.gsm:Transpile2StatementsResult */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function89(void) {/* ./src/transpiler.gsm:transpile2Statements/txt// */
	uint8_t local_num8[6] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[7] = {0};
	char *local_text[21] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[5] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], const_num8[0]);
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], global_num64[0]);
	local_num8[0] = const_num8[0];
	local_num8[1] = const_num8[1];
	local_num8[2] = const_num8[2];
	local_num8[3] = const_num8[3];
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalCmplx*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum8*/
	GVM_CMPLX_ASSIGN(global_cmplx[13], ((GVM_CMPLX_TAKE(global_cmplx[13]))->elements[global_num8[5]]));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	GVM_CMPLX_ASSIGN(global_cmplx[14], ((GVM_CMPLX_TAKE(global_cmplx[14]))->elements[global_num8[5]]));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for U2I*/
	/*WARNING: Incomplete Instruction Set Translation for SubI*/
	local_num64[5] = const_num8[1];
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	GVM_CMPLX_ASSIGN(global_cmplx[13], ((GVM_CMPLX_TAKE(global_cmplx[13]))->elements[global_num8[5]]));
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_U2I(const_num16[1]) == global_num8[5]), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[0]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation for UnaryMinusI*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	GVM_CMPLX_ASSIGN(local_cmplx[4], (GVM_U2I(const_num8[4]) == GVM_U2I(global_num64[4])));
	GVM_CMPLX_ASSIGN(local_cmplx[4], ((GVM_CMPLX_TAKE(local_cmplx[4]))->elements[const_num8[17]]));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	GVM_CMPLX_ASSIGN(local_cmplx[4], ((GVM_CMPLX_TAKE(local_cmplx[4]))->elements[const_num8[18]]));
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[4]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[4]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[2]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[2]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[2]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[2]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[2]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[2]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[3]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[3]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[2]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	local_num64[6] = (gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5])));
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)global_num64[6]), 0)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[2]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[0]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[0]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[2]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[2]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[0])), ((uint64_t)(gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)global_num64[5])))), 6)));
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[0])), ((uint64_t)(gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)global_num64[5])))), 6)));
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[0])), ((uint64_t)(gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)global_num64[5])))), 6)));
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[0])), ((uint64_t)(gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)global_num64[5])))), 6)));
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[0])), ((uint64_t)(gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)global_num64[5])))), 6)));
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[0])), ((uint64_t)(gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)global_num64[5])))), 6)));
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[0])), ((uint64_t)(gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)global_num64[5])))), 6)));
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[0])), ((uint64_t)(gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)global_num64[5])))), 6)));
	/*WARNING: Incomplete Instruction Set Translation for I2U*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], const_num8[1]);
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)global_num64[5]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for U2Text*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], (gvm_cmplx_add((gvm_cmplx_remove((GVM_CMPLX_TAKE(local_cmplx[1])), ((uint64_t)(GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[5])))))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(local_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[2])), ((uint64_t)global_num8[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxClone*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (GVM_CMPLX_TAKE(local_cmplx[0])));
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function90(void) {/* ./libs/fs.gsm:ResultTxt */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function91(void) {/* ./libs/fs.gsm:ResultFile */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function92(void) {/* ./libs/fs.gsm:ResultDir */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function93(void) {/* ./libs/fs.gsm:Path */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function94(void) {/* ./libs/fs.gsm:Exists/Path/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Swap*/
	/*WARNING: Incomplete Instruction Set Translation for EqIU*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function95(void) {/* ./libs/fs.gsm:Type/Path/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for GllExec*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function96(void) {/* ./libs/fs.gsm:AsFile/Path/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Not*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function97(void) {/* ./libs/fs.gsm:AsDir/Path/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Not*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function98(void) {/* ./libs/fs.gsm:File */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function99(void) {/* ./libs/fs.gsm:Read/File/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Not*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for GllExec*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function100(void) {/* ./libs/fs.gsm:Exists/File/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for GllExec*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function101(void) {/* ./libs/fs.gsm:Dir */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function102(void) {/* ./libs/fs.gsm:List/Dir/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Not*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for TextConcat*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for GllExec*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function103(void) {/* ./libs/fs.gsm:Exists/Dir/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for GllExec*/
	/*WARNING: Incomplete Instruction Set Translation for TextHash*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function104(void) {/* ./src/byteReader.gsm:ByteReader */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum64*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function105(void) {/* ./src/byteReader.gsm:hasNext/ByteReader/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetSize*/
	/*WARNING: Incomplete Instruction Set Translation for LessU*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function106(void) {/* ./src/byteReader.gsm:next/ByteReader/ */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Not*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfTrue*/
	/*WARNING: Incomplete Instruction Set Translation for JumpPos*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextGetChar*/
	local_num8[0] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for AddU*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxAddElement*/
	/*WARNING: Incomplete Instruction Set Translation for CmplxBuildEmpty*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Pop*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function107(void) {/* ./src/byteReader.gsm:nextULong/ByteReader/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ShiftL*/
	local_num64[0] = (const_num8[87] | global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ShiftL*/
	local_num64[0] = (const_num8[34] | global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ShiftL*/
	local_num64[0] = (const_num8[88] | global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ShiftL*/
	local_num64[0] = (const_num8[89] | global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ShiftL*/
	local_num64[0] = (const_num8[90] | global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ShiftL*/
	local_num64[0] = (const_num8[25] | global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ShiftL*/
	local_num64[0] = (const_num8[24] | global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Or*/
	local_num64[0] = global_num64[0];
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function108(void) {/* ./src/byteReader.gsm:nextUInt/ByteReader/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[1] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num32[0] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ShiftL*/
	local_num32[0] = (const_num8[90] | global_num32[0]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ShiftL*/
	local_num32[0] = (const_num8[25] | global_num32[0]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ShiftL*/
	local_num32[0] = (const_num8[24] | global_num32[0]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Or*/
	local_num32[0] = global_num32[0];
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function109(void) {/* ./src/byteReader.gsm:nextUShort/ByteReader/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[1] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num16[0] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for ShiftL*/
	local_num16[0] = (const_num8[24] | global_num16[0]);
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for Or*/
	local_num16[0] = global_num16[0];
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}
void $function110(void) {/* ./src/byteReader.gsm:nextBuffer/ByteReader/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[1] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation for LoadArgument*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstText*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalNum32*/
	local_num64[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation for JumpPosIfFalse*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for LoadConstFunc*/
	/*WARNING: Incomplete Instruction Set Translation for CallFunc*/
	/*WARNING: Incomplete Instruction Set Translation for TextAddChar*/
	/*WARNING: Incomplete Instruction Set Translation for StoreLocalText*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation for JumpNeg*/
	/*WARNING: Incomplete Instruction Set Translation for LoadLocalText*/
	/*WARNING: Incomplete Instruction Set Translation for ReturnElement*/
}

