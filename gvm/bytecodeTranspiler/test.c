
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
void $function71(void); /* test.gsm:main */
void $function72(void); /* ./libs/system.gsm:isNull/txt/ */
void $function73(void); /* ./libs/system.gsm:$_getStructDescription_$/txt/ */
void $function74(void); /* ./libs/system.gsm:$_constructor_$/ */
void $function75(void); /* ./libs/system.gsm:$_selectText_$/txt/txt/ */
void $function76(void); /* ./libs/system.gsm:$_selectUInt_$/txt/txt/ */
void $function77(void); /* ./libs/system.gsm:$_selectInt_$/txt/txt/ */
void $function78(void); /* ./libs/system.gsm:$_selectFloat_$/txt/txt/ */
void $function79(void); /* ./libs/system.gsm:$_update_$/ */
void $function80(void); /* ./libs/system.gsm:drop */
void $function81(void); /* ./libs/system.gsm:classOf/txt/ */
void $function82(void); /* ./libs/system.gsm:fieldsOf/txt/ */
const uint8_t  const_num8[38] = {0,
0,
0,
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
48};
const uint16_t const_num16[1] = {2000};
const uint32_t const_num32[0] = {};
const uint64_t const_num64[1] = {0};
const char *const_text[75] = {"undefined",
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
"G2.9",
"(",
",",
":",
"Field isn't a valid formatType!"};

uint8_t global_num8[27] = {0};
uint16_t global_num16[1] = {0};
uint32_t global_num32[0] = {0};
uint64_t global_num64[0] = {0};
char *global_text[8] = {NULL};
void *global_func[0] = {NULL};
gvm_cmplx_t *global_cmplx[13] = {NULL};

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
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	global_num8[17] = const_num8[17];
	global_num8[18] = const_num8[18];
	global_num8[19] = const_num8[19];
	global_num8[20] = const_num8[20];
	global_num8[21] = const_num8[21];
	global_num8[22] = const_num8[22];
	global_num8[23] = const_num8[23];
	global_num8[24] = const_num8[24];
	global_num8[25] = const_num8[25];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	global_num16[0] = const_num16[0];
	global_num8[26] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], const_num8[17]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], const_num8[0]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], const_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], const_num8[17]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[9], const_num8[17]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[10], const_num8[17]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[12], const_num8[17]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function1(void) {/* ./libs/std.gsm:getFormatType// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function2(void) {/* ./libs/std.gsm:cmp/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[1] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num32[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num32[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num32[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function3(void) {/* ./libs/std.gsm:same/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[1] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num32[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num32[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num32[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function4(void) {/* ./libs/std.gsm:upper/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = (GVM_I2U(GVM_U2I(const_num8[28]) - GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function5(void) {/* ./libs/std.gsm:reverse/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[1];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function6(void) {/* ./libs/std.gsm:pause/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function7(void) {/* ./libs/std.gsm:argsCheck/multi/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[3] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function8(void) {/* ./libs/std.gsm:outerr/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function9(void) {/* ./libs/std.gsm:jErr/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function10(void) {/* ./libs/std.gsm:logWarning/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function11(void) {/* ./libs/std.gsm:abort/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function12(void) {/* ./libs/std.gsm:assert//txt/ */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function13(void) {/* ./libs/std.gsm:progressbar/txt//// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[6] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[3] = (GVM_F2U(GVM_U2F(global_num64[1]) / GVM_U2F(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[4] = (GVM_F2U(GVM_U2F(global_num64[2]) * GVM_U2F(global_num64[3])));
	local_num64[5] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[5] = (const_num8[18] + global_num64[5]);
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[5] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[5] = (const_num8[18] + global_num64[5]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[5] = (const_num8[18] + global_num64[5]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function14(void) {/* ./libs/std.gsm:fill/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function15(void) {/* ./libs/std.gsm:fillWith/txt/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = (GVM_U2I((GVM_I2U(GVM_U2I(const_num8[18]) + GVM_U2I(global_num64[0])))) < (GVM_U2I(const_num8[0]) > GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = (const_num8[18] + global_num64[1]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) * GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = (GVM_U2I((GVM_I2U(GVM_U2I(const_num8[18]) + GVM_U2I(global_num64[0])))) < (GVM_U2I((GVM_I2U(GVM_U2I(const_num8[18]) + GVM_U2I(global_num64[0])))) < global_num64[1]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = (const_num8[18] + global_num64[1]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function16(void) {/* ./libs/std.gsm:indexOfTxtInList/multi/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[17];
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function17(void) {/* ./libs/std.gsm:indexOfSameTxtInList/multi/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[17];
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function18(void) {/* ./libs/std.gsm:toBytes/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[0])), ((uint64_t)global_num64[0]), 0)));
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function19(void) {/* ./libs/std.gsm:ccolor// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[1] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function20(void) {/* ./libs/std.gsm:isUpper// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function21(void) {/* ./libs/std.gsm:isLower// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function22(void) {/* ./libs/std.gsm:isNumeric// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function23(void) {/* ./libs/std.gsm:isAlpha// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function24(void) {/* ./libs/std.gsm:isAlphaNumeric// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function25(void) {/* ./libs/std.gsm:isWhitespace// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function26(void) {/* ./libs/std.gsm:isInText//txt/ */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function27(void) {/* ./libs/std.gsm:filter/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[3] = {0};
	char *local_text[3] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[2] = global_num64[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function28(void) {/* ./libs/std.gsm:insertText/txt/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[3] = {0};
	char *local_text[3] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = (const_num8[18] + global_num64[1]);
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[2] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[2] = (const_num8[18] + global_num64[2]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = (const_num8[18] + global_num64[1]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function29(void) {/* ./libs/std.gsm:subText/txt/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[3] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[2] = global_num64[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[2] = (const_num8[18] + global_num64[2]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function30(void) {/* ./libs/std.gsm:StringRepresentation/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (const_num8[18] + global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function31(void) {/* ./libs/std.gsm:SQLStringRepresentation/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (const_num8[18] + global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function32(void) {/* ./libs/std.gsm:getChar/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function33(void) {/* ./libs/std.gsm:mulText/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function34(void) {/* ./libs/std.gsm:Str/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[2] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[17];
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (const_num8[18] + global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function35(void) {/* ./libs/std.gsm:getIndexInText/txt// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function36(void) {/* ./libs/std.gsm:stripMargin/txt/ */
	uint8_t local_num8[2] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num8[1] = global_num64[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num8[1] = global_num64[0];
	local_num64[0] = (const_num8[18] + global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (const_num8[18] - global_num64[0]);
	local_num64[0] = (const_num8[18] + global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function37(void) {/* ./libs/std.gsm:makeString/multi/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[17];
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (const_num8[18] + global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function38(void) {/* ./libs/std.gsm:replace/txt/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[4] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[1];
	local_num64[1] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[1];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = global_num64[1];
	local_num64[1] = (GVM_I2U(GVM_U2I(global_num64[0]) + GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function39(void) {/* ./libs/std.gsm:countChar/txt// */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[0];
	local_num64[1] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	local_num64[1] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function40(void) {/* ./libs/std.gsm:startsWith/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function41(void) {/* ./libs/std.gsm:split/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[3] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[0];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add(global_num64[0], ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[0]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (GVM_I2U(GVM_U2I((GVM_I2U(GVM_U2I(const_num8[1]) - GVM_U2I(global_num64[0])))) + GVM_U2I((GVM_I2U(GVM_U2I(global_num64[0]) + GVM_U2I(global_num64[0]))))));
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add(global_num64[0], ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[0]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function42(void) {/* ./libs/std.gsm:getArgument/multi/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[4] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[0];
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function43(void) {/* ./libs/tracer.gsm:function_tracer_enter/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	global_num8[26] = const_num8[18];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], (gvm_cmplx_add(const_num8[1], ((uint64_t)(GVM_CMPLX_TAKE(global_cmplx[1]))), 4)));
	GVM_CMPLX_ASSIGN(global_cmplx[2], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[2])), ((uint64_t)global_num64[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function44(void) {/* ./libs/tracer.gsm:function_tracer_leave/txt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->number_of_elements));
	local_num64[1] = (const_num8[18] - const_num8[17]);
	GVM_CMPLX_ASSIGN(global_cmplx[1], const_num8[18]);
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[2], const_num8[18]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function45(void) {/* ./libs/tracer.gsm:printStackTrace/ */
	uint8_t local_num8[1] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[5] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[17];
	local_num8[0] = const_num8[17];
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[2], ((GVM_CMPLX_TAKE(global_cmplx[2]))->number_of_elements));
	local_num64[1] = (const_num8[18] - const_num8[17]);
	GVM_CMPLX_ASSIGN(global_cmplx[1], const_num8[18]);
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[2], const_num8[18]);
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[2] = const_num8[17];
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->number_of_elements));
	local_num64[4] = (const_num8[18] - (gvm_cmplx_remove((GVM_CMPLX_TAKE(global_cmplx[2])), ((uint64_t)global_num64[1]))));
	GVM_CMPLX_ASSIGN(global_cmplx[2], ((GVM_CMPLX_TAKE(global_cmplx[2]))->elements[global_num64[4]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num8[0] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[2], ((GVM_CMPLX_TAKE(global_cmplx[2]))->elements[global_num64[4]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], ((GVM_CMPLX_TAKE(global_cmplx[1]))->elements[global_num64[4]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num8[0] = const_num8[18];
	GVM_CMPLX_ASSIGN(global_cmplx[2], ((GVM_CMPLX_TAKE(global_cmplx[2]))->elements[global_num64[4]]));
	local_num64[0] = (!global_num8[0]);
	GVM_CMPLX_ASSIGN(global_cmplx[2], global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[1], global_num64[0]);
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[2] = (const_num8[18] + global_num64[2]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function46(void) {/* ./libs/tracer.gsm:$$GVMErrorHandler$$/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function47(void) {/* ./libs/classic.gsm:dumpMemoryUse/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[4] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], ((GVM_CMPLX_TAKE(global_cmplx[3]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], ((GVM_CMPLX_TAKE(global_cmplx[3]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], ((GVM_CMPLX_TAKE(global_cmplx[4]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], ((GVM_CMPLX_TAKE(global_cmplx[4]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], ((GVM_CMPLX_TAKE(global_cmplx[5]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], ((GVM_CMPLX_TAKE(global_cmplx[5]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[6], ((GVM_CMPLX_TAKE(global_cmplx[6]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[0];
	local_num64[1] = const_num8[0];
	GVM_CMPLX_ASSIGN(global_cmplx[6], ((GVM_CMPLX_TAKE(global_cmplx[6]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[6], ((GVM_CMPLX_TAKE(global_cmplx[6]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = (GVM_I2U(GVM_U2I(global_num64[0]) + GVM_U2I((GVM_U2I(global_num64[1]) > (GVM_I2U(GVM_U2I(const_num8[8]) * GVM_U2I((GVM_I2U(GVM_U2I(const_num8[8]) * GVM_U2I(const_num8[8]))))))))));
	local_num64[1] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[12], ((GVM_CMPLX_TAKE(global_cmplx[12]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[2] = const_num8[8];
	local_num64[1] = const_num8[0];
	GVM_CMPLX_ASSIGN(global_cmplx[12], ((GVM_CMPLX_TAKE(global_cmplx[12]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[11], ((GVM_CMPLX_TAKE(global_cmplx[11]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[2] = (GVM_I2U(GVM_U2I(global_num64[2]) + GVM_U2I((GVM_U2I(global_num64[1]) > global_num64[0]))));
	local_num64[1] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[3] = const_num8[37];
	local_num64[1] = const_num8[0];
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[3] = (GVM_I2U(GVM_U2I(global_num64[3]) + GVM_U2I((GVM_U2I(global_num64[1]) > global_num64[2]))));
	local_num64[1] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[1])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function48(void) {/* ./libs/classic.gsm:UInt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], ((GVM_CMPLX_TAKE(global_cmplx[3]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[3])), ((uint64_t)global_num64[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function49(void) {/* ./libs/classic.gsm:getUInt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[3], ((GVM_CMPLX_TAKE(global_cmplx[3]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function50(void) {/* ./libs/classic.gsm:updateUInt/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
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
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], ((GVM_CMPLX_TAKE(global_cmplx[4]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[4])), ((uint64_t)global_num64[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function52(void) {/* ./libs/classic.gsm:getInt// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[4], ((GVM_CMPLX_TAKE(global_cmplx[4]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function53(void) {/* ./libs/classic.gsm:updateInt/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
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
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], ((GVM_CMPLX_TAKE(global_cmplx[5]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[5])), ((uint64_t)global_num64[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function55(void) {/* ./libs/classic.gsm:getFloat// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[5], ((GVM_CMPLX_TAKE(global_cmplx[5]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function56(void) {/* ./libs/classic.gsm:updateFloat/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
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
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[6], ((GVM_CMPLX_TAKE(global_cmplx[6]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[6], (GVM_CMPLX_TAKE(global_cmplx[6])));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function58(void) {/* ./libs/classic.gsm:getText// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[6], ((GVM_CMPLX_TAKE(global_cmplx[6]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function59(void) {/* ./libs/classic.gsm:updateText//txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
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
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[7])), ((uint64_t)global_num64[0]), 0)));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], (GVM_CMPLX_TAKE(global_cmplx[8])));
	GVM_CMPLX_ASSIGN(global_cmplx[9], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[9])), ((uint64_t)global_num64[1]), 0)));
	GVM_CMPLX_ASSIGN(global_cmplx[10], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[10])), ((uint64_t)global_num64[2]), 0)));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function61(void) {/* ./libs/classic.gsm:Object/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[11], ((GVM_CMPLX_TAKE(global_cmplx[11]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[11], (GVM_CMPLX_TAKE(global_cmplx[11])));
	GVM_CMPLX_ASSIGN(global_cmplx[12], (gvm_cmplx_add((GVM_CMPLX_TAKE(global_cmplx[12])), ((uint64_t)const_num8[17]), 0)));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function62(void) {/* ./libs/classic.gsm:classOfObject// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[11], ((GVM_CMPLX_TAKE(global_cmplx[11]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function63(void) {/* ./libs/classic.gsm:objectToText// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function64(void) {/* ./libs/classic.gsm:fieldsOfObject// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[12], ((GVM_CMPLX_TAKE(global_cmplx[12]))->elements[global_num64[0]]));
	local_num64[1] = (GVM_CMPLX_TAKE(local_cmplx[0]));
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((!(const_num8[17] == (const_num8[17] == global_num64[0]))), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[0]))), 4)));
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((!(const_num8[17] == global_num64[1])), ((uint64_t)(GVM_CMPLX_TAKE(local_cmplx[0]))), 4)));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function65(void) {/* ./libs/classic.gsm:typeOfField// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[10], ((GVM_CMPLX_TAKE(global_cmplx[10]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function66(void) {/* ./libs/classic.gsm:putField//txt/// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[5] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[3] = global_num64[2];
	GVM_CMPLX_ASSIGN(global_cmplx[12], ((GVM_CMPLX_TAKE(global_cmplx[12]))->elements[global_num64[0]]));
	local_num64[4] = global_num64[1];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[12], (GVM_CMPLX_STORE(global_num64[0], global_num64[3], (GVM_CMPLX_TAKE(global_cmplx[12])))));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[4]]));
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[4]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[4]]));
	local_num64[4] = ((!(!(const_num8[17] == const_num8[18]))) & (const_num8[17] == global_num64[4]));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[4]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], (GVM_CMPLX_STORE(global_num64[4], global_num64[3], (GVM_CMPLX_TAKE(global_cmplx[7])))));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[9], (GVM_CMPLX_STORE(global_num64[4], global_num64[1], (GVM_CMPLX_TAKE(global_cmplx[9])))));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function67(void) {/* ./libs/classic.gsm:getField//txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[12], ((GVM_CMPLX_TAKE(global_cmplx[12]))->elements[global_num64[0]]));
	local_num64[1] = const_num8[17];
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[9], ((GVM_CMPLX_TAKE(global_cmplx[9]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[1]]));
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[1]]));
	local_num64[1] = (!(!(const_num8[17] == ((!(const_num8[17] == global_num64[1])) & (const_num8[17] == global_num64[0])))));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[9], ((GVM_CMPLX_TAKE(global_cmplx[9]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function68(void) {/* ./libs/classic.gsm:getFieldReference//txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[12], ((GVM_CMPLX_TAKE(global_cmplx[12]))->elements[global_num64[0]]));
	local_num64[1] = const_num8[17];
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[1]]));
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[7], ((GVM_CMPLX_TAKE(global_cmplx[7]))->elements[global_num64[1]]));
	local_num64[1] = ((!(!(const_num8[17] == global_num64[1]))) & ((!(const_num8[17] == global_num64[1])) & (const_num8[17] == global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[8], ((GVM_CMPLX_TAKE(global_cmplx[8]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function69(void) {/* ./libs/classic.gsm:getFieldValue// */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[9], ((GVM_CMPLX_TAKE(global_cmplx[9]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function70(void) {/* ./libs/classic.gsm:collectByClass/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[3] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[0] = const_num8[0];
	GVM_CMPLX_ASSIGN(global_cmplx[11], ((GVM_CMPLX_TAKE(global_cmplx[11]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(global_cmplx[11], ((GVM_CMPLX_TAKE(global_cmplx[11]))->elements[global_num64[0]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], (gvm_cmplx_add((GVM_CMPLX_TAKE(local_cmplx[0])), ((uint64_t)global_num64[0]), 0)));
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[1]) + GVM_U2I(global_num64[0])));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function71(void) {/* test.gsm:main */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[0] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	local_num64[0] = (GVM_I2U(GVM_U2I(const_num8[3]) + GVM_U2I(const_num8[1])));
}
void $function72(void) {/* ./libs/system.gsm:isNull/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function73(void) {/* ./libs/system.gsm:$_getStructDescription_$/txt/ */
	uint8_t local_num8[2] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num8[1] = const_num8[17];
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function74(void) {/* ./libs/system.gsm:$_constructor_$/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[4] = {0};
	char *local_text[4] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[5] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[17]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = const_num8[18];
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->number_of_elements));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[2], ((GVM_CMPLX_TAKE(local_cmplx[2]))->elements[(const_num8[18] - global_num64[1])]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[4], global_num64[1]);
	GVM_CMPLX_ASSIGN(local_cmplx[4], ((GVM_CMPLX_TAKE(local_cmplx[4]))->elements[const_num8[17]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[global_num64[1]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	local_num64[1] = (const_num8[18] + global_num64[1]);
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function75(void) {/* ./libs/system.gsm:$_selectText_$/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function76(void) {/* ./libs/system.gsm:$_selectUInt_$/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function77(void) {/* ./libs/system.gsm:$_selectInt_$/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function78(void) {/* ./libs/system.gsm:$_selectFloat_$/txt/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[1] = {0};
	char *local_text[2] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function79(void) {/* ./libs/system.gsm:$_update_$/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[2] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[2] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[17]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[18]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[1], ((GVM_CMPLX_TAKE(local_cmplx[1]))->elements[const_num8[19]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[19]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[19]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[19]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[19]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	GVM_CMPLX_ASSIGN(local_cmplx[0], ((GVM_CMPLX_TAKE(local_cmplx[0]))->elements[const_num8[19]]));
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function80(void) {/* ./libs/system.gsm:drop */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function81(void) {/* ./libs/system.gsm:classOf/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[0] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}
void $function82(void) {/* ./libs/system.gsm:fieldsOf/txt/ */
	uint8_t local_num8[0] = {0};
	uint16_t local_num16[0] = {0};
	uint32_t local_num32[0] = {0};
	uint64_t local_num64[0] = {0};
	char *local_text[1] = {NULL};
	void *local_func[0] = {NULL};
	gvm_cmplx_t *local_cmplx[1] = {NULL};
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
	/*WARNING: Incomplete Instruction Set Translation*/
}

