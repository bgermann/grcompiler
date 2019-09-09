/*--------------------------------------------------------------------*//*:Ignore this sentence.
Copyright (C) 1999, 2001 SIL International. All rights reserved.

Distributable under the terms of either the Common Public License or the
GNU Lesser General Public License, as specified in the LICENSING.txt file.

File: Main.h
Responsibility: Sharon Correll
Last reviewed: Not yet.

Description:
    Constant definitions.
-------------------------------------------------------------------------------*//*:End Ignore*/


enum {
	// Maximum Silf table version that can be generated by this version of the compiler:
	kfxdCompilerVersion = 0x00050000,
	kfxdMaxSilfVersion  = 0x00050000
};

enum {
	kMaxGlyphsPerFont = 65530,
	// Reserve 6 glyphs for defined constants.
	kBadGlyph = 65531
};

// Expected type of result of expression
typedef enum ExpressionType {	// hungarian: expt
	kexptUnknown,
	kexptNumber,
	kexptBoolean,
	kexptMeas,
	kexptZero,	// to handle the fact that 0 == 0m == false
	kexptOne,	// to handle the fact that 1 == true
	kexptSlotRef,
	kexptString,
	kexptPoint,
	kexptGlyphID
} ExpressionType;


bool EquivalentTypes(ExpressionType expt1, ExpressionType expt2);


//	Glyph types:
typedef enum GlyphType {	// hungarian: glft
	kglftUnknown = 0,
	kglftUnicode,
	kglftGlyphID,
	kglftCodepoint,
	kglftPostscript,
	kglftPseudo
} GlyphType;


typedef enum GlyphClassType {	// hungarian: glfct
	kglfctUnion = 0,
	kglfctIntersect,
	kglfctDifference
} GlyphClassType;


//	Symbol types
typedef enum SymbolType {	// hungarian: symt
	ksymtNone,
	ksymtClass,					// user-defined
	ksymtPseudo,				// user-defined
	ksymtDirective,				// pre-defined
	ksymtFeature,				// user-defined
		ksymtFeatStyle,			// user-defined
	ksymtFeatSetting,			// user-defined
	ksymtLanguage,				// user defined
	ksymtGlobal,				// pre-defined
	ksymtGlyphData,
		ksymtGlyphAttr,			// pre-defined and user-defined
			ksymtGlyphAttrComp,	// user-defined: component.???.top/bottom/right/left
		ksymtGlyphMetric,		// pre-defined
	ksymtInvalid,
		ksymtNonLeafGlyphAttr,	// a non-leaf field within a glyph attribute
	ksymtNameID,				// user-defined
	ksymtOperator,				// pre-defined: ==, &&, +, -, min, max, etc.
		ksymtOpAssign,
	ksymtProcState,				// pre-defined: JustifyMode, JustifyLevel, RunDirection
	ksymtSlotAttr,				// pre-defined
		ksymtSlotAttrPtOff,		// pre-defined: attach.at/with, shift, kern--attributes with
								//		point values that need to be expanded into integers,
								//		possibly with offsets
		ksymtSlotAttrPt,		// pre-defined: collision.min/max--point values with no offsets
		ksymtSlotAttrCompRef,	// user-defined: component.???.reference
	ksymtSpecial,				// pre-defined: _, @, #, ^, etc.
		ksymtSpecialAt,
		ksymtSpecialCaret,
		ksymtSpecialLb,
		ksymtSpecialUnderscore,
	ksymtTable,					// pre-defined: feature, glyph, name
		ksymtTableRule,			// pre-defined: linebreak, substitution, position
	ksymtUnit					// pre-defined: 'm'
} SymbolType;


//	Scaling units:
enum {
	kmunitUnscaled	= -2,	// already converted from scaled to unscaled
	kmunitNone		= -1,	// no scaling
	kmunitDefault	=  0	// use default
};


//	Table options for rule-checking:
typedef enum RuleCheckOption {
	kfrcoNone = 0,
	kfrcoLb			= 0x0001,	// can LB items be in the rule?
	kfrcoSubst		= 0x0002,	// can substitutions be done?
	kfrcoSetBreak	= 0x0004,	// set breakweight attribute?
	kfrcoSetCompRef = 0x0008,	// set component.ref attr?
	kfrcoSetDir		= 0x0010,	// set directionality attr?
	kfrcoSetInsert	= 0x0020,	// set insertion attr?
	kfrcoSetPos		= 0x0040,	// set attach, shift, kern attrs?
	kfrcoPreBidi	= 0x0080,	// justifiy.stretch/shrink vs. justify.width
	kfrcoNeedJust	= 0x0100	// need tests for justification
} RuleCheckOption;


typedef enum TableType {	// hungarian: tblt
	ktbltNone,
	ktbltName,
	ktbltFeature,
	ktbltGlyph,
	ktbltRule,
	ktbltLanguage
} TableType;


//	Maxima permitted by the binary format of the TrueType tables.
enum {
	kMaxSubTables			= 256,
	kMaxGlyphAttrs			= 65536,	// Gloc table
	kMinGlyphAttrValue	   = -32768,
	kMaxGlyphAttrValue		= 32768,
	kMaxPasses				= 128,		// Sil_sub table would allow 256
	kMaxPseudos				= 65536,
	kMaxScriptTags			= 256,
	kMaxReplcmtClasses		= 65535,	// Class map
	kMaxReplcmtClassesV1_2	= 256,
	kMaxGlyphAttrsGlat1		= 256,
	kMaxComponents			= 16383,
	kMaxColIterations		= 7,			// iterations per collision pass
	kMaxCollisionThreshold	= 255
};


//	Maxima permitted by the engine implementation. These codes MUST match those used by
//	the engine.
enum {
	kMaxFontNameLength		=    32,	// font cache name buffer size
	kMaxFeatures			=    64,
	kFieldsPerComponent		=     4,	// four corners of the box
	kMaxSlotsPerRule		=    64,
	kMaxGlyphsPerInputClass	= 65535,
	kMaxTotalGlyphs			= 65535
};

//	Pragmatic maxima:
enum {
	//	Maxima imposed by the binary tables = 256
	kMaxUserDefinableSlotAttrs	= 64,
	kMaxComponentsPerGlyph		= 32,
	kMaxJustLevel				= 3	// ie, justify.0-3.xxx are permitted, justify.4.xxx is not
};

//	Other constants

enum {
	kMaxFileLineNumber = 0x1FFFFFFF,	//	kludge to ensure that certain error messages come last

	kPassPerSPbitmap = 16,	// *skipPasses* bitmap; 16 = size of glyph attr word

	kCollisionThresholdDefault = 10,

	kFullPass = 2		// do a full bidi pass
};


//	Engine code operators. These codes MUST match those used by the engine.
enum ActionCommand {
	kopNop = 0,

	kopPushByte,		kopPushByteU,		kopPushShort,	kopPushShortU,	kopPushLong,

	kopAdd,				kopSub,				kopMul,			kopDiv,
	kopMin,				kopMax,
	kopNeg,
	kopTrunc8,			kopTrunc16,

	kopCond,
	
	kopAnd,				kopOr,				kopNot,
	kopEqual,			kopNotEq,
	kopLess,			kopGtr,				kopLessEq,		kopGtrEq,

	kopNext,			kopNextN,			kopCopyNext,
	kopPutGlyphV1_2,	kopPutSubsV1_2,		kopPutCopy,
	kopInsert,			kopDelete,
	kopAssoc,
	kopCntxtItem,

	kopAttrSet,			kopAttrAdd,			kopAttrSub,
	kopAttrSetSlot,
	kopIAttrSetSlot,
	kopPushSlotAttr,		kopPushGlyphAttrV1_2,	kopPushGlyphMetric,		kopPushFeat,
	kopPushAttToGAttrV1_2,	kopPushAttToGlyphMetric,
	kopPushISlotAttr,

	kopPushIGlyphAttr,	// not yet implemented

	kopPopRet,			kopRetZero,			kopRetTrue,
	kopIAttrSet,		kopIAttrAdd,		kopIAttrSub,
	kopPushProcState,	kopPushVersion,
	kopPutSubs,			kopPutSubs2,		kopPutSubs3,
	kopPutGlyph,		kopPushGlyphAttr,	kopPushAttToGlyphAttr,

	kopBitAnd,			kopBitOr,			kopBitNot,
	kopSetBits,
	// not implemented:
	//kopAttrBitAnd,		kopAttrBitOr,		kopIAttrBitAnd,		kopIAttrBitOr,

	kopFeatSet,
	kopLim
};


//	Slot attribute internal IDs. These codes MUST match those used by the engine.
enum SlotAttrName {
	kslatBogus = -1,	// used for psuedo slot attribute
	kslatAdvX = 0,		kslatAdvY,
	kslatAttTo,
	kslatAttAtX,		kslatAttAtY,		kslatAttAtGpt,
	kslatAttAtXoff,		kslatAttAtYoff,
	kslatAttWithX,		kslatAttWithY,		kslatAttWithGpt,
	kslatAttWithXoff,	kslatAttWithYoff,
	kslatAttLevel,
	kslatBreak,
	kslatCompRef,
	kslatDir,
	kslatInsert,
	kslatPosX,			kslatPosY,
	kslatShiftX,		kslatShiftY,
	kslatUserDefnV1, // version 1.0
	kslatMeasureSol,	kslatMeasureEol,
	kslatJ0Stretch,		kslatJ0Shrink,		kslatJ0Step,	kslatJ0Weight,	kslatJ0Width,
	kslatJ1Stretch,		kslatJ1Shrink,		kslatJ1Step,	kslatJ1Weight,	kslatJ1Width,
	kslatJ2Stretch,		kslatJ2Shrink,		kslatJ2Step,	kslatJ2Weight,	kslatJ2Width,
	kslatJ3Stretch,		kslatJ3Shrink,		kslatJ3Step,	kslatJ3Weight,	kslatJ3Width,
	kslatSegSplit = kslatJ0Stretch + 29,
	kslatUserDefn = kslatJ0Stretch + 30,
	kslatBidiLevel,		// used in Graphite2 engine
	kslatColFlags,
	kslatColMinX,		kslatColMinY,		kslatColMaxX,	kslatColMaxY,
	kslatColFixX,		kslatColFixY,		//read-only attr - how much adjustment was made
	kslatColMargin,		kslatColMarginWt,
	kslatColExclGlyph,	kslatColExclOffX,	kslatColExclOffY,
	kslatSeqClass,		kslatSeqProxClass,	kslatSeqOrder,
	kslatSeqAboveXoff,	kslatSeqAboveWt,	kslatSeqBelowXlim,	kslatSeqBelowWt, kslatSeqValignHt, kslatSeqValignWt

};


//	Glyph metric internal IDs. These codes MUST match those used by the engine.
typedef enum GlyphMetric {
	kgmetLsb = 0,		kgmetRsb,
	kgmetBbTop,			kgmetBbBottom,		kgmetBbLeft,		kgmetBbRight,
	kgmetBbHeight,		kgmetBbWidth,
	kgmetAdvWidth,		kgmetAdvHeight,
	kgmetAscent,		kgmetDescent
} GlyphMetric;


//	Directionality codes. These codes MUST match those used by the engine.
typedef enum DirCode {  // Hungarian: dirc

	kdircUnknown	= -1,	// not yet determined by the bidi algorithm
	kdircNeutral	=  0,	// other neutrals (default) - ON
	kdircL			=  1,	// left-to-right, strong - L
	kdircR			=  2,	// right-to-left, strong - R
	kdircRArab		=  3,	// Arabic letter, right-to-left, strong, AR
	kdircEuroNum	=  4,	// European number, left-to-right, weak - EN
	kdircEuroSep	=  5,	// European separator, left-to-right, weak - ES
	kdircEuroTerm	=  6,	// European number terminator, left-to-right, weak - ET
	kdircArabNum	=  7,	// Arabic number, left-to-right, weak - AN
	kdircComSep		=  8,	// Common number separator, left-to-right, weak - CS
	kdircWhiteSpace	=  9,	// white space, neutral - WS
	kdircBndNeutral = 10,	// boundary netural - BN

	kdircLRO		= 11,	// LTR override
	kdircRLO		= 12,	// RTL override
	kdircLRE		= 13,	// LTR embedding
	kdircRLE		= 14,	// RTL embedding
	kdircPDF		= 15,	// pop directionality flag

	//	I think we need this too:
	kdircNSM		= 16,	// non-space mark

	// Not used by Graphite1:
	kdircLRI		= 17,	// LTR isolate
	kdircRLI		= 18,	// RTL isolate
	kdircFSI		= 19,	// first strong isolate
	kdircPDI		= 20,	// pop isolate run flag

	// Not used by Graphite1:
	kdircOPP		= 21,	// opening parens
	kdircCPP		= 22,	// closing parens

	//	Special values for internal use:
	kdircLlb		= 32,	// left-to-right line-break
	kdircRlb		= 33,	// right-to-left line-break
	kdircPDFl		= 34,	// PDF marker matching an LRO or LRE
	kdircPDFr		= 35	// PDF marker matching an RLO or RLE

} DirCode;


//	Unicode characters with special treatments
enum DefinedChars {

	kchwSpace	= 0x0020,		// space
	kchwHyphen	= 0x002D,		// hyphen

	kchwLRM		= 0x200E,		// left-to-right mark
	kchwRLM		= 0x200F,		// right-to-left mark
	kchwALM		= 0x061C,		// Arabic letter mark
	kchwLRE		= 0x202A,		// left-to-right embedding
	kchwRLE		= 0x202B,		// right-to-left embedding
	kchwPDF		= 0x202C,		// pop directional format
	kchwLRO		= 0x202D,		// left-to-right override
	kchwRLO		= 0x202E,		// right-to-left override
	kchwLRI		= 0x2066,		// left-to-right isolate
	kchwRLI		= 0x2067,		// right-to-left isolate
	kchwFSI		= 0x2068,		// first strong isolate
	kchwPDI		= 0x2069		// pop directional isolate
};

// version 1.0 breakweights
enum BreakWeightsV1
{
	klbv1WordBreak		= 1,
	klbv1HyphenBreak	= 2,
	klbv1LetterBreak	= 3,
	klbv1ClipBreak		= 4
};

enum BreakWeightsV2
{
	klbv2WsBreak		= 10,
	klbv2WordBreak		= 15,
	klbv2HyphenBreak	= 20,
	klbv2LetterBreak	= 30,
	klbv2ClipBreak		= 40
};

enum SpaceContextuals
{
	kspconUnknown		= 0,
	kspconNone			= 1,
	kspconFirstOnly		= 2,	// only as first slot in rule
	kspconLastOnly		= 3,	// only as last slot in rule
	kspconSingleOnly	= 4,	// only as the single slot in rule
	kspconEdgeOnly		= 5,	// only as first or last slot, never in the middle of the rules
	kspconAnywhere		= 6		// middle of a rule
};

//	Gpoint = zero value. This code MUST match that used by the engine.
//	Most unset attributes have a default value of zero, but gpoint attributes need something
//	to distinguish between an actual value of zero and nothing. (This is a somewhat arbitrary
//	value, except we want to avoid -1 because that often used by the engine to indicate
//	"never been set").
enum {
	kGpointZero = -2
};

enum ProcessStates
{
	kpstatJustifyMode	= 1,
	kpstatJustifyLevel	= 2
};

enum JustifyModes
{
	kjmodNormal		= 0,
	kjmodMeasure	= 1,
	kjmodJustify	= 2
};

// Auto-kerning
enum {
	kakNone = 0,
	kakFull = 1,
	kakNoSpace = 2
};

enum {
	kInvalid = 0x3FFFFFFF
};