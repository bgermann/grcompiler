/* $ANTLR 2.7.7 (20170711): "GrpParser.g" -> "GrpParser.cpp"$ */
#include "GrpParser.hpp"
#include <antlr/NoViableAltException.hpp>
#include <antlr/SemanticException.hpp>
#include <antlr/ASTFactory.hpp>
#line 54 "GrpParser.g"

//	Insert at the beginning of the GrpParser.cpp file
#pragma warning(disable:4101)
#include "Grp.h"

//	This function needs to go in the .cpp file, not the .hpp file, after the
//	GrpASTNode class is defined.
void GrpParser::init(GrpTokenStreamFilter & tsf)
{
	m_ptsf = &tsf;
	setASTNodeFactory(new GrpASTNode());
}

void GrpParser::reportError(const antlr::RecognitionException& ex)
{
	//	Pipe the error back through the token stream filter, so it can supply the
	//	line-and-file information.
	m_ptsf->ReportParserError(ex);
}


#line 29 "GrpParser.cpp"
GrpParser::GrpParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,k)
{
}

GrpParser::GrpParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,3)
{
}

GrpParser::GrpParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,k)
{
}

GrpParser::GrpParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,3)
{
}

GrpParser::GrpParser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(state,3)
{
}

void GrpParser::renderDescription() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST renderDescription_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST D_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		declarationList();
		D_AST = returnAST;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp1_AST = astFactory->create(LT(1));
		match(ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE);
		renderDescription_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 105 "GrpParser.g"
		renderDescription_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Ztop))->add(D_AST)));
#line 70 "GrpParser.cpp"
		currentAST.root = renderDescription_AST;
		if ( renderDescription_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			renderDescription_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = renderDescription_AST->getFirstChild();
		else
			currentAST.child = renderDescription_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_0);
	}
	returnAST = renderDescription_AST;
}

void GrpParser::declarationList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST declarationList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case IDENT:
			case LITERAL_glyph:
			case LITERAL_position:
			{
				globalDecl();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_environment:
			case LITERAL_table:
			{
				topDecl();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			default:
			{
				goto _loop4;
			}
			}
		}
		_loop4:;
		} // ( ... )*
		declarationList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_0);
	}
	returnAST = declarationList_AST;
}

void GrpParser::globalDecl() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST globalDecl_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		identDot();
		astFactory->addASTChild( currentAST, returnAST );
		{
		switch ( LA(1)) {
		case OP_EQ:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp2_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp2_AST);
			match(OP_EQ);
			break;
		}
		case OP_PLUSEQUAL:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp3_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp3_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp3_AST);
			match(OP_PLUSEQUAL);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		if ((LA(1) == OP_LPAREN) && (_tokenSet_1.member(LA(2))) && (_tokenSet_2.member(LA(3)))) {
			match(OP_LPAREN);
			exprList();
			astFactory->addASTChild( currentAST, returnAST );
			match(OP_RPAREN);
		}
		else if ((_tokenSet_1.member(LA(1))) && (_tokenSet_3.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			expr();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_glyph:
		case LITERAL_position:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		globalDecl_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_5);
	}
	returnAST = globalDecl_AST;
}

void GrpParser::topDecl() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST topDecl_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		switch ( LA(1)) {
		case LITERAL_environment:
		{
			topEnvironDecl();
			astFactory->addASTChild( currentAST, returnAST );
			topDecl_AST = currentAST.root;
			break;
		}
		case LITERAL_table:
		{
			tableDecl();
			astFactory->addASTChild( currentAST, returnAST );
			topDecl_AST = currentAST.root;
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_4);
	}
	returnAST = topDecl_AST;
}

void GrpParser::topEnvironDecl() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST topEnvironDecl_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp7_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp7_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp7_AST);
		match(LITERAL_environment);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_SEMI:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_glyph:
		case LITERAL_position:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_glyph:
		case LITERAL_position:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case LITERAL_environment:
			case LITERAL_table:
			{
				topDecl();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case IDENT:
			case LITERAL_glyph:
			case LITERAL_position:
			{
				globalDecl();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			default:
			{
				goto _loop14;
			}
			}
		}
		_loop14:;
		} // ( ... )*
		match(LITERAL_endenvironment);
		{
		if ((LA(1) == OP_SEMI) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			match(OP_SEMI);
		}
		else if ((_tokenSet_4.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		topEnvironDecl_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_4);
	}
	returnAST = topEnvironDecl_AST;
}

void GrpParser::tableDecl() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST tableDecl_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp11_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp11_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp11_AST);
		match(LITERAL_table);
		{
		if ((LA(1) == OP_LPAREN) && (LA(2) == LITERAL_name)) {
			tableName();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((LA(1) == OP_LPAREN) && (LA(2) == LITERAL_glyph)) {
			tableGlyph();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((LA(1) == OP_LPAREN) && (LA(2) == LITERAL_feature)) {
			tableFeature();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((LA(1) == OP_LPAREN) && (LA(2) == LITERAL_language)) {
			tableLanguage();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((LA(1) == OP_LPAREN) && (LA(2) == LITERAL_substitution)) {
			tableSub();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((LA(1) == OP_LPAREN) && (LA(2) == LITERAL_justification)) {
			tableJust();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((LA(1) == OP_LPAREN) && (LA(2) == LITERAL_position || LA(2) == LITERAL_positioning)) {
			tablePos();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((LA(1) == OP_LPAREN) && (LA(2) == LITERAL_linebreak)) {
			tableLineBreak();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((LA(1) == OP_LPAREN) && (LA(2) == IDENT)) {
			tableOther();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		match(LITERAL_endtable);
		{
		if ((LA(1) == OP_SEMI) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			match(OP_SEMI);
		}
		else if ((_tokenSet_4.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		tableDecl_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_4);
	}
	returnAST = tableDecl_AST;
}

void GrpParser::identDot() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST identDot_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		if ((LA(1) == IDENT || LA(1) == LITERAL_position) && (LA(2) == OP_DOT) && (LA(3) == IDENT || LA(3) == LITERAL_glyph || LA(3) == LITERAL_position)) {
			{
			switch ( LA(1)) {
			case IDENT:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp14_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp14_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp14_AST);
				match(IDENT);
				break;
			}
			case LITERAL_position:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp15_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp15_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp15_AST);
				match(LITERAL_position);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp16_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp16_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp16_AST);
			match(OP_DOT);
			identDot();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((LA(1) == IDENT || LA(1) == LITERAL_glyph || LA(1) == LITERAL_position) && (_tokenSet_6.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			{
			switch ( LA(1)) {
			case IDENT:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp17_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp17_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp17_AST);
				match(IDENT);
				break;
			}
			case LITERAL_position:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp18_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp18_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp18_AST);
				match(LITERAL_position);
				break;
			}
			case LITERAL_glyph:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp19_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp19_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp19_AST);
				match(LITERAL_glyph);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		identDot_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = identDot_AST;
}

void GrpParser::exprList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST exprList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		expr();
		astFactory->addASTChild( currentAST, returnAST );
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == OP_COMMA)) {
				match(OP_COMMA);
				expr();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop368;
			}
			
		}
		_loop368:;
		} // ( ... )*
		exprList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_7);
	}
	returnAST = exprList_AST;
}

void GrpParser::expr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST expr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		conditionalExpr();
		astFactory->addASTChild( currentAST, returnAST );
		expr_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_8);
	}
	returnAST = expr_AST;
}

void GrpParser::directives() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST directives_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST D_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		directiveList();
		D_AST = returnAST;
		directives_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 140 "GrpParser.g"
		directives_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zdirectives))->add(D_AST)));
#line 564 "GrpParser.cpp"
		currentAST.root = directives_AST;
		if ( directives_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			directives_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = directives_AST->getFirstChild();
		else
			currentAST.child = directives_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_9);
	}
	returnAST = directives_AST;
}

void GrpParser::directiveList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST directiveList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(OP_LBRACE);
		{
		switch ( LA(1)) {
		case IDENT:
		{
			directive();
			astFactory->addASTChild( currentAST, returnAST );
			{ // ( ... )*
			for (;;) {
				if ((LA(1) == OP_SEMI) && (LA(2) == IDENT) && (LA(3) == OP_EQ)) {
					match(OP_SEMI);
					directive();
					astFactory->addASTChild( currentAST, returnAST );
				}
				else {
					goto _loop20;
				}
				
			}
			_loop20:;
			} // ( ... )*
			{
			switch ( LA(1)) {
			case OP_SEMI:
			{
				match(OP_SEMI);
				break;
			}
			case OP_RBRACE:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case OP_RBRACE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_RBRACE);
		directiveList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_9);
	}
	returnAST = directiveList_AST;
}

void GrpParser::directive() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST directive_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp25_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp25_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp25_AST);
		match(IDENT);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp26_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp26_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp26_AST);
		match(OP_EQ);
		expr();
		astFactory->addASTChild( currentAST, returnAST );
		directive_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_10);
	}
	returnAST = directive_AST;
}

void GrpParser::tableName() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST tableName_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(OP_LPAREN);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp28_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp28_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp28_AST);
		match(LITERAL_name);
		match(OP_RPAREN);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_SEMI:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LIT_INT:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LIT_INT:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case LITERAL_environment:
			{
				nameEnv();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case IDENT:
			case LIT_INT:
			{
				nameSpecList();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_table:
			{
				tableDecl();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			default:
			{
				goto _loop30;
			}
			}
		}
		_loop30:;
		} // ( ... )*
		tableName_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_11);
	}
	returnAST = tableName_AST;
}

void GrpParser::tableGlyph() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST tableGlyph_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(OP_LPAREN);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp32_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp32_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp32_AST);
		match(LITERAL_glyph);
		match(OP_RPAREN);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_SEMI:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case LITERAL_environment:
			{
				glyphEnv();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case IDENT:
			{
				glyphEntry();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_table:
			{
				tableDecl();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			default:
			{
				goto _loop64;
			}
			}
		}
		_loop64:;
		} // ( ... )*
		tableGlyph_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_11);
	}
	returnAST = tableGlyph_AST;
}

void GrpParser::tableFeature() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST tableFeature_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(OP_LPAREN);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp36_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp36_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp36_AST);
		match(LITERAL_feature);
		match(OP_RPAREN);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_SEMI:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_name:
		case LIT_INT:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_name:
		case LIT_INT:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case LITERAL_environment:
			{
				featureEnv();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case IDENT:
			case LITERAL_name:
			case LIT_INT:
			{
				featureSpecList();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_table:
			{
				tableDecl();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			default:
			{
				goto _loop129;
			}
			}
		}
		_loop129:;
		} // ( ... )*
		tableFeature_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_11);
	}
	returnAST = tableFeature_AST;
}

void GrpParser::tableLanguage() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST tableLanguage_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(OP_LPAREN);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp40_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp40_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp40_AST);
		match(LITERAL_language);
		match(OP_RPAREN);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_SEMI:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case LITERAL_environment:
			{
				languageEnv();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case IDENT:
			{
				languageSpecList();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_table:
			{
				tableDecl();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			default:
			{
				goto _loop156;
			}
			}
		}
		_loop156:;
		} // ( ... )*
		tableLanguage_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_11);
	}
	returnAST = tableLanguage_AST;
}

void GrpParser::tableSub() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST tableSub_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(OP_LPAREN);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp44_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp44_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp44_AST);
		match(LITERAL_substitution);
		match(OP_RPAREN);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_LPAREN:
		case OP_SEMI:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_12.member(LA(1)))) {
				subEntry();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop187;
			}
			
		}
		_loop187:;
		} // ( ... )*
		tableSub_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_11);
	}
	returnAST = tableSub_AST;
}

void GrpParser::tableJust() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST tableJust_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(OP_LPAREN);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp48_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp48_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp48_AST);
		match(LITERAL_justification);
		match(OP_RPAREN);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_LPAREN:
		case OP_SEMI:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_12.member(LA(1)))) {
				subEntry();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop269;
			}
			
		}
		_loop269:;
		} // ( ... )*
		tableJust_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_11);
	}
	returnAST = tableJust_AST;
}

void GrpParser::tablePos() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST tablePos_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(OP_LPAREN);
		{
		switch ( LA(1)) {
		case LITERAL_position:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp52_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp52_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp52_AST);
			match(LITERAL_position);
			break;
		}
		case LITERAL_positioning:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp53_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp53_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp53_AST);
			match(LITERAL_positioning);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_RPAREN);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_LPAREN:
		case OP_SEMI:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_12.member(LA(1)))) {
				posEntry();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop275;
			}
			
		}
		_loop275:;
		} // ( ... )*
		tablePos_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_11);
	}
	returnAST = tablePos_AST;
}

void GrpParser::tableLineBreak() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST tableLineBreak_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(OP_LPAREN);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp57_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp57_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp57_AST);
		match(LITERAL_linebreak);
		match(OP_RPAREN);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_LPAREN:
		case OP_SEMI:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_12.member(LA(1)))) {
				posEntry();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop319;
			}
			
		}
		_loop319:;
		} // ( ... )*
		tableLineBreak_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_11);
	}
	returnAST = tableLineBreak_AST;
}

void GrpParser::tableOther() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST tableOther_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(OP_LPAREN);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp61_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp61_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp61_AST);
		match(IDENT);
		match(OP_RPAREN);
		{
		if ((LA(1) == OP_LBRACE) && (LA(2) == OP_RBRACE || LA(2) == IDENT) && ((LA(3) >= OP_EQ && LA(3) <= AT_IDENT))) {
			directives();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if (((LA(1) >= OP_EQ && LA(1) <= AT_IDENT)) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		{
		if ((LA(1) == OP_SEMI) && ((LA(2) >= OP_EQ && LA(2) <= AT_IDENT)) && (_tokenSet_4.member(LA(3)))) {
			match(OP_SEMI);
		}
		else if (((LA(1) >= OP_EQ && LA(1) <= AT_IDENT)) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_13.member(LA(1)))) {
				otherEntry();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop341;
			}
			
		}
		_loop341:;
		} // ( ... )*
		tableOther_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_11);
	}
	returnAST = tableOther_AST;
}

void GrpParser::nameEnv() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST nameEnv_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp64_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp64_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp64_AST);
		match(LITERAL_environment);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_SEMI:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LIT_INT:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LIT_INT:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case IDENT:
			case LIT_INT:
			{
				nameSpecList();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_environment:
			{
				nameEnv();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_table:
			{
				tableDecl();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			default:
			{
				goto _loop35;
			}
			}
		}
		_loop35:;
		} // ( ... )*
		match(LITERAL_endenvironment);
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LIT_INT:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		nameEnv_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_14);
	}
	returnAST = nameEnv_AST;
}

void GrpParser::nameSpecList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST nameSpecList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		if ((LA(1) == IDENT || LA(1) == LIT_INT) && (LA(2) == OP_LBRACE)) {
			nameSpecStruct();
			astFactory->addASTChild( currentAST, returnAST );
			{
			if ((LA(1) == IDENT || LA(1) == LIT_INT) && (_tokenSet_15.member(LA(2))) && (_tokenSet_16.member(LA(3)))) {
				nameSpecList();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else if ((_tokenSet_17.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
		}
		else if ((LA(1) == IDENT || LA(1) == LIT_INT) && (LA(2) == OP_EQ || LA(2) == OP_DOT || LA(2) == OP_PLUS_EQUAL)) {
			nameSpecFlat();
			astFactory->addASTChild( currentAST, returnAST );
			{
			if ((LA(1) == OP_SEMI) && (LA(2) == IDENT || LA(2) == LIT_INT) && (_tokenSet_15.member(LA(3)))) {
				match(OP_SEMI);
				nameSpecList();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else if ((_tokenSet_17.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			{
			if ((LA(1) == OP_SEMI) && (_tokenSet_17.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
				match(OP_SEMI);
			}
			else if ((_tokenSet_17.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		nameSpecList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_17);
	}
	returnAST = nameSpecList_AST;
}

void GrpParser::nameSpecStruct() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST nameSpecStruct_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  N = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST N_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  I = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST I_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LIT_INT:
		{
			N = LT(1);
			N_AST = astFactory->create(N);
			match(LIT_INT);
			break;
		}
		case IDENT:
		{
			I = LT(1);
			I_AST = astFactory->create(I);
			match(IDENT);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_LBRACE);
		{
		switch ( LA(1)) {
		case IDENT:
		case LIT_INT:
		{
			nameSpecList();
			X_AST = returnAST;
			break;
		}
		case OP_RBRACE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_RBRACE);
		{
		if ((LA(1) == OP_SEMI) && (_tokenSet_17.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			match(OP_SEMI);
		}
		else if ((_tokenSet_17.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		nameSpecStruct_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 192 "GrpParser.g"
		nameSpecStruct_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(4))->add(astFactory->create(ZdotStruct))->add(N_AST)->add(I_AST)->add(X_AST)));
#line 1782 "GrpParser.cpp"
		currentAST.root = nameSpecStruct_AST;
		if ( nameSpecStruct_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			nameSpecStruct_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = nameSpecStruct_AST->getFirstChild();
		else
			currentAST.child = nameSpecStruct_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_17);
	}
	returnAST = nameSpecStruct_AST;
}

void GrpParser::nameSpecFlat() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST nameSpecFlat_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  N = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST N_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  I = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST I_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  D = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST D_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  E1 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST E1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  E2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST E2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST Vi1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST Vi2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LIT_INT:
		{
			N = LT(1);
			N_AST = astFactory->create(N);
			match(LIT_INT);
			break;
		}
		case IDENT:
		{
			I = LT(1);
			I_AST = astFactory->create(I);
			match(IDENT);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_DOT:
		{
			D = LT(1);
			D_AST = astFactory->create(D);
			match(OP_DOT);
			{
			if ((LA(1) == IDENT || LA(1) == LIT_INT) && (LA(2) == OP_EQ || LA(2) == OP_DOT || LA(2) == OP_PLUS_EQUAL)) {
				nameSpecFlat();
				X1_AST = returnAST;
			}
			else if ((LA(1) == IDENT || LA(1) == LIT_INT) && (LA(2) == OP_LBRACE)) {
				nameSpecStruct();
				X2_AST = returnAST;
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			nameSpecFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 197 "GrpParser.g"
			nameSpecFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(5))->add(D_AST)->add(N_AST)->add(I_AST)->add(X1_AST)->add(X2_AST)));
#line 1864 "GrpParser.cpp"
			currentAST.root = nameSpecFlat_AST;
			if ( nameSpecFlat_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				nameSpecFlat_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = nameSpecFlat_AST->getFirstChild();
			else
				currentAST.child = nameSpecFlat_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		case OP_EQ:
		case OP_PLUS_EQUAL:
		{
			{
			switch ( LA(1)) {
			case OP_EQ:
			{
				E1 = LT(1);
				E1_AST = astFactory->create(E1);
				match(OP_EQ);
				break;
			}
			case OP_PLUS_EQUAL:
			{
				E2 = LT(1);
				E2_AST = astFactory->create(E2);
				match(OP_PLUS_EQUAL);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case LIT_INT:
			case OP_PLUS:
			case OP_MINUS:
			case LITERAL_true:
			case LITERAL_false:
			{
				signedInt();
				Vi1_AST = returnAST;
				break;
			}
			case OP_LPAREN:
			case LIT_STRING:
			case LITERAL_string:
			{
				stringDefn();
				Vi2_AST = returnAST;
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			nameSpecFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 201 "GrpParser.g"
			nameSpecFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(6))->add(E1_AST)->add(E2_AST)->add(N_AST)->add(I_AST)->add(Vi1_AST)->add(Vi2_AST)));
#line 1928 "GrpParser.cpp"
			currentAST.root = nameSpecFlat_AST;
			if ( nameSpecFlat_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				nameSpecFlat_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = nameSpecFlat_AST->getFirstChild();
			else
				currentAST.child = nameSpecFlat_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_17);
	}
	returnAST = nameSpecFlat_AST;
}

void GrpParser::signedInt() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST signedInt_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LITERAL_true:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp73_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp73_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp73_AST);
			match(LITERAL_true);
			break;
		}
		case LITERAL_false:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp74_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp74_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp74_AST);
			match(LITERAL_false);
			break;
		}
		case LIT_INT:
		case OP_PLUS:
		case OP_MINUS:
		{
			{
			switch ( LA(1)) {
			case OP_PLUS:
			{
				match(OP_PLUS);
				break;
			}
			case OP_MINUS:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp76_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp76_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp76_AST);
				match(OP_MINUS);
				break;
			}
			case LIT_INT:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp77_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp77_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp77_AST);
			match(LIT_INT);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		signedInt_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_18);
	}
	returnAST = signedInt_AST;
}

void GrpParser::stringDefn() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST stringDefn_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LIT_STRING:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp78_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp78_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp78_AST);
			match(LIT_STRING);
			break;
		}
		case LITERAL_string:
		{
			stringFunc();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_LPAREN:
		{
			{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp79_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp79_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp79_AST);
			match(OP_LPAREN);
			stringDefn();
			astFactory->addASTChild( currentAST, returnAST );
			{ // ( ... )*
			for (;;) {
				if ((_tokenSet_19.member(LA(1)))) {
					{
					switch ( LA(1)) {
					case OP_COMMA:
					{
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp80_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
						tmp80_AST = astFactory->create(LT(1));
						astFactory->addASTChild(currentAST, tmp80_AST);
						match(OP_COMMA);
						break;
					}
					case OP_LPAREN:
					case LIT_STRING:
					case LITERAL_string:
					{
						break;
					}
					default:
					{
						throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
					}
					}
					}
					stringDefn();
					astFactory->addASTChild( currentAST, returnAST );
				}
				else {
					goto _loop57;
				}
				
			}
			_loop57:;
			} // ( ... )*
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp81_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp81_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp81_AST);
			match(OP_RPAREN);
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		stringDefn_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_20);
	}
	returnAST = stringDefn_AST;
}

void GrpParser::stringFunc() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST stringFunc_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp82_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp82_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp82_AST);
		match(LITERAL_string);
		match(OP_LPAREN);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp84_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp84_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp84_AST);
		match(LIT_STRING);
		{
		switch ( LA(1)) {
		case OP_COMMA:
		{
			match(OP_COMMA);
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp86_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp86_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp86_AST);
			match(LIT_INT);
			break;
		}
		case OP_RPAREN:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_RPAREN);
		stringFunc_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_20);
	}
	returnAST = stringFunc_AST;
}

void GrpParser::glyphEnv() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST glyphEnv_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp88_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp88_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp88_AST);
		match(LITERAL_environment);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_SEMI:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case IDENT:
			{
				glyphEntry();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_environment:
			{
				glyphEnv();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_table:
			{
				tableDecl();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			default:
			{
				goto _loop69;
			}
			}
		}
		_loop69:;
		} // ( ... )*
		match(LITERAL_endenvironment);
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		glyphEnv_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_21);
	}
	returnAST = glyphEnv_AST;
}

void GrpParser::glyphEntry() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST glyphEntry_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		if ((LA(1) == IDENT) && (_tokenSet_22.member(LA(2)))) {
			glyphContents();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((LA(1) == IDENT) && (LA(2) == OP_LBRACE || LA(2) == OP_DOT)) {
			glyphAttrs();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		glyphEntry_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_21);
	}
	returnAST = glyphEntry_AST;
}

void GrpParser::glyphContents() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST glyphContents_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp93_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp93_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp93_AST);
		match(IDENT);
		{
		{
		switch ( LA(1)) {
		case OP_EQ:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp94_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp94_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp94_AST);
			match(OP_EQ);
			break;
		}
		case OP_PLUSEQUAL:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp95_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp95_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp95_AST);
			match(OP_PLUSEQUAL);
			break;
		}
		case OP_ANDEQUAL:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp96_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp96_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp96_AST);
			match(OP_ANDEQUAL);
			break;
		}
		case OP_MINUSEQUAL:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp97_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp97_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp97_AST);
			match(OP_MINUSEQUAL);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		glyphSpec();
		astFactory->addASTChild( currentAST, returnAST );
		}
		{
		if ((_tokenSet_23.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			attributes();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((_tokenSet_24.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		glyphContents_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_24);
	}
	returnAST = glyphContents_AST;
}

void GrpParser::glyphAttrs() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST glyphAttrs_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  I = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST I_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST A_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X3_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		I = LT(1);
		I_AST = astFactory->create(I);
		match(IDENT);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			match(OP_LBRACE);
			{
			switch ( LA(1)) {
			case IDENT:
			case LIT_INT:
			case LITERAL_glyph:
			case LITERAL_justify:
			case LITERAL_min:
			case LITERAL_max:
			{
				attrItemList();
				X1_AST = returnAST;
				break;
			}
			case OP_RBRACE:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(OP_RBRACE);
#line 242 "GrpParser.g"
			A_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zattrs))->add(X1_AST)));
#line 2443 "GrpParser.cpp"
			break;
		}
		case OP_DOT:
		{
			match(OP_DOT);
			{
			if ((_tokenSet_25.member(LA(1))) && (_tokenSet_26.member(LA(2)))) {
				attrItemFlat();
				X2_AST = returnAST;
			}
			else if ((_tokenSet_25.member(LA(1))) && (LA(2) == OP_LBRACE)) {
				attrItemStruct();
				X3_AST = returnAST;
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
#line 245 "GrpParser.g"
			A_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(astFactory->create(Zattrs))->add(X2_AST)->add(X3_AST)));
#line 2465 "GrpParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		glyphAttrs_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 247 "GrpParser.g"
		glyphAttrs_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(astFactory->create(OP_PLUSEQUAL))->add(I_AST)->add(A_AST)));
#line 2477 "GrpParser.cpp"
		currentAST.root = glyphAttrs_AST;
		if ( glyphAttrs_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			glyphAttrs_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = glyphAttrs_AST->getFirstChild();
		else
			currentAST.child = glyphAttrs_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_24);
	}
	returnAST = glyphAttrs_AST;
}

void GrpParser::glyphSpec() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST glyphSpec_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case IDENT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp101_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp101_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp101_AST);
			match(IDENT);
			break;
		}
		case LITERAL_codepoint:
		{
			codepointFunc();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_glyphid:
		{
			glyphidFunc();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_postscript:
		{
			postscriptFunc();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_unicode:
		{
			unicodeFunc();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LIT_UHEX:
		{
			unicodeCodepoint();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_pseudo:
		{
			pseudoFunc();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_LPAREN:
		{
			{
			match(OP_LPAREN);
			{
			switch ( LA(1)) {
			case OP_LPAREN:
			case IDENT:
			case LITERAL_pseudo:
			case LIT_UHEX:
			case LITERAL_codepoint:
			case LITERAL_glyphid:
			case LITERAL_postscript:
			case LITERAL_unicode:
			{
				glyphSpec();
				astFactory->addASTChild( currentAST, returnAST );
				{ // ( ... )*
				for (;;) {
					if ((_tokenSet_27.member(LA(1)))) {
						{
						switch ( LA(1)) {
						case OP_COMMA:
						{
							match(OP_COMMA);
							break;
						}
						case OP_LPAREN:
						case IDENT:
						case LITERAL_pseudo:
						case LIT_UHEX:
						case LITERAL_codepoint:
						case LITERAL_glyphid:
						case LITERAL_postscript:
						case LITERAL_unicode:
						{
							break;
						}
						default:
						{
							throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
						}
						}
						}
						glyphSpec();
						astFactory->addASTChild( currentAST, returnAST );
					}
					else {
						goto _loop88;
					}
					
				}
				_loop88:;
				} // ( ... )*
				break;
			}
			case OP_RPAREN:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(OP_RPAREN);
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		glyphSpec_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_28);
	}
	returnAST = glyphSpec_AST;
}

void GrpParser::attributes() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST attributes_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			match(OP_LBRACE);
			{
			switch ( LA(1)) {
			case IDENT:
			case LIT_INT:
			case LITERAL_glyph:
			case LITERAL_justify:
			case LITERAL_min:
			case LITERAL_max:
			{
				attrItemList();
				X_AST = returnAST;
				break;
			}
			case OP_SEMI:
			case OP_RBRACE:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case OP_SEMI:
			{
				match(OP_SEMI);
				break;
			}
			case OP_RBRACE:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(OP_RBRACE);
			attributes_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 669 "GrpParser.g"
			attributes_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zattrs))->add(X_AST)));
#line 2687 "GrpParser.cpp"
			currentAST.root = attributes_AST;
			if ( attributes_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				attributes_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = attributes_AST->getFirstChild();
			else
				currentAST.child = attributes_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		case OP_LPAREN:
		case OP_SEMI:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case OP_GT:
		case OP_DIV:
		case OP_QUESTION:
		case OP_LBRACKET:
		case OP_RBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_29);
	}
	returnAST = attributes_AST;
}

void GrpParser::attrItemList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST attrItemList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		if ((_tokenSet_25.member(LA(1))) && (LA(2) == OP_LBRACE)) {
			attrItemStruct();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((_tokenSet_25.member(LA(1))) && (_tokenSet_26.member(LA(2)))) {
			attrItemFlat();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		{
		if ((LA(1) == OP_SEMI) && (_tokenSet_25.member(LA(2))) && (_tokenSet_30.member(LA(3)))) {
			match(OP_SEMI);
			attrItemList();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((LA(1) == OP_SEMI || LA(1) == OP_RBRACE) && (_tokenSet_31.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		attrItemList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_10);
	}
	returnAST = attrItemList_AST;
}

void GrpParser::attrItemFlat() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST attrItemFlat_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST I_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  D = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST D_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST E_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST V1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST V2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		attrName();
		I_AST = returnAST;
		}
		{
		switch ( LA(1)) {
		case OP_DOT:
		{
			D = LT(1);
			D_AST = astFactory->create(D);
			match(OP_DOT);
			{
			if ((_tokenSet_25.member(LA(1))) && (_tokenSet_26.member(LA(2)))) {
				attrItemFlat();
				X1_AST = returnAST;
			}
			else if ((_tokenSet_25.member(LA(1))) && (LA(2) == OP_LBRACE)) {
				attrItemStruct();
				X2_AST = returnAST;
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			attrItemFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 690 "GrpParser.g"
			attrItemFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(4))->add(D_AST)->add(I_AST)->add(X1_AST)->add(X2_AST)));
#line 2819 "GrpParser.cpp"
			currentAST.root = attrItemFlat_AST;
			if ( attrItemFlat_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				attrItemFlat_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = attrItemFlat_AST->getFirstChild();
			else
				currentAST.child = attrItemFlat_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		case OP_EQ:
		case OP_PLUSEQUAL:
		case OP_MINUSEQUAL:
		case OP_DIVEQUAL:
		case OP_MULTEQUAL:
		{
			attrAssignOp();
			E_AST = returnAST;
			{
			if ((LA(1) == IDENT) && (LA(2) == OP_LPAREN) && (_tokenSet_32.member(LA(3)))) {
				function();
				V1_AST = returnAST;
			}
			else if ((_tokenSet_1.member(LA(1))) && (_tokenSet_33.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
				expr();
				V2_AST = returnAST;
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			attrItemFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 694 "GrpParser.g"
			attrItemFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(4))->add(E_AST)->add(I_AST)->add(V1_AST)->add(V2_AST)));
#line 2854 "GrpParser.cpp"
			currentAST.root = attrItemFlat_AST;
			if ( attrItemFlat_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				attrItemFlat_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = attrItemFlat_AST->getFirstChild();
			else
				currentAST.child = attrItemFlat_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_34);
	}
	returnAST = attrItemFlat_AST;
}

void GrpParser::attrItemStruct() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST attrItemStruct_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST I_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		attrName();
		I_AST = returnAST;
		}
		match(OP_LBRACE);
		{
		switch ( LA(1)) {
		case IDENT:
		case LIT_INT:
		case LITERAL_glyph:
		case LITERAL_justify:
		case LITERAL_min:
		case LITERAL_max:
		{
			attrItemList();
			X_AST = returnAST;
			break;
		}
		case OP_SEMI:
		case OP_RBRACE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_RBRACE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_RBRACE);
		attrItemStruct_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 678 "GrpParser.g"
		attrItemStruct_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(astFactory->create(ZdotStruct))->add(I_AST)->add(X_AST)));
#line 2936 "GrpParser.cpp"
		currentAST.root = attrItemStruct_AST;
		if ( attrItemStruct_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			attrItemStruct_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = attrItemStruct_AST->getFirstChild();
		else
			currentAST.child = attrItemStruct_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_34);
	}
	returnAST = attrItemStruct_AST;
}

void GrpParser::codepointFunc() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST codepointFunc_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  F = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST F_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  N = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST N_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		F = LT(1);
		F_AST = astFactory->create(F);
		match(LITERAL_codepoint);
		match(OP_LPAREN);
		codepointList();
		X_AST = returnAST;
		{
		switch ( LA(1)) {
		case OP_COMMA:
		{
			match(OP_COMMA);
			N = LT(1);
			N_AST = astFactory->create(N);
			match(LIT_INT);
#line 269 "GrpParser.g"
			C_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zcodepage))->add(N_AST)));
#line 2980 "GrpParser.cpp"
			break;
		}
		case OP_RPAREN:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_RPAREN);
		codepointFunc_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 271 "GrpParser.g"
		codepointFunc_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(F_AST)->add(C_AST)->add(X_AST)));
#line 2997 "GrpParser.cpp"
		currentAST.root = codepointFunc_AST;
		if ( codepointFunc_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			codepointFunc_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = codepointFunc_AST->getFirstChild();
		else
			currentAST.child = codepointFunc_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_35);
	}
	returnAST = codepointFunc_AST;
}

void GrpParser::glyphidFunc() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST glyphidFunc_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp115_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp115_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp115_AST);
		match(LITERAL_glyphid);
		match(OP_LPAREN);
		intOrRange();
		astFactory->addASTChild( currentAST, returnAST );
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == LIT_INT || LA(1) == OP_COMMA)) {
				{
				switch ( LA(1)) {
				case OP_COMMA:
				{
					match(OP_COMMA);
					break;
				}
				case LIT_INT:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				intOrRange();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop107;
			}
			
		}
		_loop107:;
		} // ( ... )*
		match(OP_RPAREN);
		glyphidFunc_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_35);
	}
	returnAST = glyphidFunc_AST;
}

void GrpParser::postscriptFunc() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST postscriptFunc_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp119_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp119_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp119_AST);
		match(LITERAL_postscript);
		match(OP_LPAREN);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp121_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp121_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp121_AST);
		match(LIT_STRING);
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == LIT_STRING || LA(1) == OP_COMMA)) {
				{
				switch ( LA(1)) {
				case OP_COMMA:
				{
					match(OP_COMMA);
					break;
				}
				case LIT_STRING:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp123_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp123_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp123_AST);
				match(LIT_STRING);
			}
			else {
				goto _loop111;
			}
			
		}
		_loop111:;
		} // ( ... )*
		match(OP_RPAREN);
		postscriptFunc_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_35);
	}
	returnAST = postscriptFunc_AST;
}

void GrpParser::unicodeFunc() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST unicodeFunc_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp125_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp125_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp125_AST);
		match(LITERAL_unicode);
		match(OP_LPAREN);
		intOrRange();
		astFactory->addASTChild( currentAST, returnAST );
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == LIT_INT || LA(1) == OP_COMMA)) {
				{
				switch ( LA(1)) {
				case OP_COMMA:
				{
					match(OP_COMMA);
					break;
				}
				case LIT_INT:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				intOrRange();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop115;
			}
			
		}
		_loop115:;
		} // ( ... )*
		match(OP_RPAREN);
		unicodeFunc_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_35);
	}
	returnAST = unicodeFunc_AST;
}

void GrpParser::unicodeCodepoint() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST unicodeCodepoint_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST U_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		unicodeIntOrRange();
		U_AST = returnAST;
		astFactory->addASTChild( currentAST, returnAST );
		unicodeCodepoint_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 298 "GrpParser.g"
		unicodeCodepoint_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(ZuHex))->add(U_AST)));
#line 3189 "GrpParser.cpp"
		currentAST.root = unicodeCodepoint_AST;
		if ( unicodeCodepoint_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			unicodeCodepoint_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = unicodeCodepoint_AST->getFirstChild();
		else
			currentAST.child = unicodeCodepoint_AST;
		currentAST.advanceChildToEnd();
		unicodeCodepoint_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_35);
	}
	returnAST = unicodeCodepoint_AST;
}

void GrpParser::pseudoFunc() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST pseudoFunc_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp129_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp129_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp129_AST);
		match(LITERAL_pseudo);
		match(OP_LPAREN);
		{
		switch ( LA(1)) {
		case LITERAL_codepoint:
		{
			codepointFunc();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_glyphid:
		{
			glyphidFunc();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_postscript:
		{
			postscriptFunc();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_unicode:
		{
			unicodeFunc();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LIT_UHEX:
		{
			unicodeCodepoint();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case LIT_INT:
		case OP_COMMA:
		case LIT_UHEX:
		{
			{
			switch ( LA(1)) {
			case OP_COMMA:
			{
				match(OP_COMMA);
				break;
			}
			case LIT_INT:
			case LIT_UHEX:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case LIT_INT:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp132_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp132_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp132_AST);
				match(LIT_INT);
				break;
			}
			case LIT_UHEX:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp133_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp133_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp133_AST);
				match(LIT_UHEX);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case OP_RPAREN:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_RPAREN);
		pseudoFunc_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_28);
	}
	returnAST = pseudoFunc_AST;
}

void GrpParser::codepointList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST codepointList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case OP_LPAREN:
		{
			{
			match(OP_LPAREN);
			codepointItem();
			astFactory->addASTChild( currentAST, returnAST );
			{ // ( ... )*
			for (;;) {
				if ((_tokenSet_36.member(LA(1)))) {
					{
					switch ( LA(1)) {
					case OP_COMMA:
					{
						match(OP_COMMA);
						break;
					}
					case LIT_INT:
					case LIT_STRING:
					case LIT_CHAR:
					{
						break;
					}
					default:
					{
						throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
					}
					}
					}
					codepointItem();
					astFactory->addASTChild( currentAST, returnAST );
				}
				else {
					goto _loop101;
				}
				
			}
			_loop101:;
			} // ( ... )*
			match(OP_RPAREN);
			}
			break;
		}
		case LIT_INT:
		case LIT_STRING:
		case LIT_CHAR:
		{
			codepointItem();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		codepointList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_37);
	}
	returnAST = codepointList_AST;
}

void GrpParser::codepointItem() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST codepointItem_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LIT_STRING:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp138_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp138_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp138_AST);
			match(LIT_STRING);
			break;
		}
		case LIT_INT:
		case LIT_CHAR:
		{
			charOrIntOrRange();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		codepointItem_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_38);
	}
	returnAST = codepointItem_AST;
}

void GrpParser::charOrIntOrRange() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST charOrIntOrRange_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LIT_CHAR:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp139_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp139_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp139_AST);
			match(LIT_CHAR);
			break;
		}
		case LIT_INT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp140_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp140_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp140_AST);
			match(LIT_INT);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_DOTDOT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp141_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp141_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp141_AST);
			match(OP_DOTDOT);
			{
			switch ( LA(1)) {
			case LIT_CHAR:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp142_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp142_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp142_AST);
				match(LIT_CHAR);
				break;
			}
			case LIT_INT:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp143_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp143_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp143_AST);
				match(LIT_INT);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case OP_RPAREN:
		case LIT_INT:
		case LIT_STRING:
		case OP_COMMA:
		case LIT_CHAR:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		charOrIntOrRange_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_38);
	}
	returnAST = charOrIntOrRange_AST;
}

void GrpParser::intOrRange() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST intOrRange_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		if ((LA(1) == LIT_INT) && (LA(2) == OP_DOTDOT)) {
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp144_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp144_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp144_AST);
			match(LIT_INT);
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp145_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp145_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp145_AST);
			match(OP_DOTDOT);
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp146_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp146_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp146_AST);
			match(LIT_INT);
		}
		else if ((LA(1) == LIT_INT) && (LA(2) == OP_RPAREN || LA(2) == LIT_INT || LA(2) == OP_COMMA)) {
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp147_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp147_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp147_AST);
			match(LIT_INT);
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		intOrRange_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_39);
	}
	returnAST = intOrRange_AST;
}

void GrpParser::unicodeIntOrRange() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST unicodeIntOrRange_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		if ((LA(1) == LIT_UHEX) && (LA(2) == OP_DOTDOT)) {
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp148_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp148_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp148_AST);
			match(LIT_UHEX);
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp149_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp149_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp149_AST);
			match(OP_DOTDOT);
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp150_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp150_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp150_AST);
			match(LIT_UHEX);
		}
		else if ((LA(1) == LIT_UHEX) && (_tokenSet_35.member(LA(2)))) {
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp151_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp151_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp151_AST);
			match(LIT_UHEX);
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		unicodeIntOrRange_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_35);
	}
	returnAST = unicodeIntOrRange_AST;
}

void GrpParser::featureEnv() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST featureEnv_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp152_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp152_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp152_AST);
		match(LITERAL_environment);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_SEMI:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_name:
		case LIT_INT:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_name:
		case LIT_INT:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case IDENT:
			case LITERAL_name:
			case LIT_INT:
			{
				featureSpecList();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_environment:
			{
				featureEnv();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_table:
			{
				tableDecl();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			default:
			{
				goto _loop134;
			}
			}
		}
		_loop134:;
		} // ( ... )*
		match(LITERAL_endenvironment);
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_name:
		case LIT_INT:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		featureEnv_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_40);
	}
	returnAST = featureEnv_AST;
}

void GrpParser::featureSpecList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST featureSpecList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		if ((LA(1) == IDENT || LA(1) == LITERAL_name) && (LA(2) == OP_LBRACE)) {
			featureSpecStruct();
			astFactory->addASTChild( currentAST, returnAST );
			{
			if ((LA(1) == IDENT || LA(1) == LITERAL_name || LA(1) == LIT_INT) && (LA(2) == OP_EQ || LA(2) == OP_LBRACE || LA(2) == OP_DOT) && (_tokenSet_41.member(LA(3)))) {
				featureSpecList();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else if ((_tokenSet_42.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
		}
		else if ((LA(1) == IDENT || LA(1) == LITERAL_name || LA(1) == LIT_INT) && (LA(2) == OP_EQ || LA(2) == OP_DOT)) {
			featureSpecFlat();
			astFactory->addASTChild( currentAST, returnAST );
			{
			if ((LA(1) == OP_SEMI) && (LA(2) == IDENT || LA(2) == LITERAL_name || LA(2) == LIT_INT) && (LA(3) == OP_EQ || LA(3) == OP_LBRACE || LA(3) == OP_DOT)) {
				match(OP_SEMI);
				featureSpecList();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else if ((_tokenSet_42.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			{
			if ((LA(1) == OP_SEMI) && (_tokenSet_42.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
				match(OP_SEMI);
			}
			else if ((_tokenSet_42.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		featureSpecList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_42);
	}
	returnAST = featureSpecList_AST;
}

void GrpParser::featureSpecStruct() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST featureSpecStruct_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  I = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST I_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  In = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST In_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case IDENT:
		{
			I = LT(1);
			I_AST = astFactory->create(I);
			match(IDENT);
			break;
		}
		case LITERAL_name:
		{
			In = LT(1);
			In_AST = astFactory->create(In);
			match(LITERAL_name);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_LBRACE);
		{
		switch ( LA(1)) {
		case IDENT:
		case LITERAL_name:
		case LIT_INT:
		{
			featureSpecList();
			X_AST = returnAST;
			break;
		}
		case OP_RBRACE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_RBRACE);
		{
		if ((LA(1) == OP_SEMI) && (_tokenSet_42.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			match(OP_SEMI);
		}
		else if ((_tokenSet_42.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		featureSpecStruct_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 339 "GrpParser.g"
		featureSpecStruct_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(4))->add(astFactory->create(ZdotStruct))->add(I_AST)->add(In_AST)->add(X_AST)));
#line 3859 "GrpParser.cpp"
		currentAST.root = featureSpecStruct_AST;
		if ( featureSpecStruct_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			featureSpecStruct_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = featureSpecStruct_AST->getFirstChild();
		else
			currentAST.child = featureSpecStruct_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_42);
	}
	returnAST = featureSpecStruct_AST;
}

void GrpParser::featureSpecFlat() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST featureSpecFlat_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  I = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST I_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  In = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST In_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  D = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST D_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  E1 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST E1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST Vi1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST Vi2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  Vi3 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST Vi3_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  N = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST N_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  E2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST E2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST Vn1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST Vn2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  Vn3 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST Vn3_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case IDENT:
		case LITERAL_name:
		{
			{
			switch ( LA(1)) {
			case IDENT:
			{
				I = LT(1);
				I_AST = astFactory->create(I);
				match(IDENT);
				break;
			}
			case LITERAL_name:
			{
				In = LT(1);
				In_AST = astFactory->create(In);
				match(LITERAL_name);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case OP_DOT:
			{
				D = LT(1);
				D_AST = astFactory->create(D);
				match(OP_DOT);
				{
				if ((LA(1) == IDENT || LA(1) == LITERAL_name || LA(1) == LIT_INT) && (LA(2) == OP_EQ || LA(2) == OP_DOT)) {
					featureSpecFlat();
					X1_AST = returnAST;
				}
				else if ((LA(1) == IDENT || LA(1) == LITERAL_name) && (LA(2) == OP_LBRACE)) {
					featureSpecStruct();
					X2_AST = returnAST;
				}
				else {
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				
				}
				featureSpecFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 344 "GrpParser.g"
				featureSpecFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(5))->add(D_AST)->add(I_AST)->add(In_AST)->add(X1_AST)->add(X2_AST)));
#line 3954 "GrpParser.cpp"
				currentAST.root = featureSpecFlat_AST;
				if ( featureSpecFlat_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
					featureSpecFlat_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
					  currentAST.child = featureSpecFlat_AST->getFirstChild();
				else
					currentAST.child = featureSpecFlat_AST;
				currentAST.advanceChildToEnd();
				break;
			}
			case OP_EQ:
			{
				E1 = LT(1);
				E1_AST = astFactory->create(E1);
				match(OP_EQ);
				{
				switch ( LA(1)) {
				case LIT_INT:
				case OP_PLUS:
				case OP_MINUS:
				case LITERAL_true:
				case LITERAL_false:
				{
					signedInt();
					Vi1_AST = returnAST;
					break;
				}
				case OP_LPAREN:
				case LIT_STRING:
				case LITERAL_string:
				{
					stringDefn();
					Vi2_AST = returnAST;
					break;
				}
				case IDENT:
				{
					Vi3 = LT(1);
					Vi3_AST = astFactory->create(Vi3);
					match(IDENT);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				featureSpecFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 348 "GrpParser.g"
				featureSpecFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(6))->add(E1_AST)->add(I_AST)->add(In_AST)->add(Vi1_AST)->add(Vi2_AST)->add(Vi3_AST)));
#line 4005 "GrpParser.cpp"
				currentAST.root = featureSpecFlat_AST;
				if ( featureSpecFlat_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
					featureSpecFlat_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
					  currentAST.child = featureSpecFlat_AST->getFirstChild();
				else
					currentAST.child = featureSpecFlat_AST;
				currentAST.advanceChildToEnd();
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case LIT_INT:
		{
			N = LT(1);
			N_AST = astFactory->create(N);
			match(LIT_INT);
			E2 = LT(1);
			E2_AST = astFactory->create(E2);
			match(OP_EQ);
			{
			switch ( LA(1)) {
			case LIT_INT:
			case OP_PLUS:
			case OP_MINUS:
			case LITERAL_true:
			case LITERAL_false:
			{
				signedInt();
				Vn1_AST = returnAST;
				break;
			}
			case OP_LPAREN:
			case LIT_STRING:
			case LITERAL_string:
			{
				stringDefn();
				Vn2_AST = returnAST;
				break;
			}
			case IDENT:
			{
				Vn3 = LT(1);
				Vn3_AST = astFactory->create(Vn3);
				match(IDENT);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			featureSpecFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 353 "GrpParser.g"
			featureSpecFlat_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(5))->add(E2_AST)->add(N_AST)->add(Vn1_AST)->add(Vn2_AST)->add(Vn3_AST)));
#line 4067 "GrpParser.cpp"
			currentAST.root = featureSpecFlat_AST;
			if ( featureSpecFlat_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				featureSpecFlat_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = featureSpecFlat_AST->getFirstChild();
			else
				currentAST.child = featureSpecFlat_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_42);
	}
	returnAST = featureSpecFlat_AST;
}

void GrpParser::languageEnv() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST languageEnv_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp161_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp161_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp161_AST);
		match(LITERAL_environment);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_SEMI:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case IDENT:
			{
				languageSpecList();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_environment:
			{
				languageEnv();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LITERAL_table:
			{
				tableDecl();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			default:
			{
				goto _loop161;
			}
			}
		}
		_loop161:;
		} // ( ... )*
		match(LITERAL_endenvironment);
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		languageEnv_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_21);
	}
	returnAST = languageEnv_AST;
}

void GrpParser::languageSpecList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST languageSpecList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		if ((LA(1) == IDENT) && (LA(2) == OP_LBRACE || LA(2) == OP_DOT) && (_tokenSet_43.member(LA(3)))) {
			languageSpec();
			astFactory->addASTChild( currentAST, returnAST );
			{
			if ((LA(1) == IDENT) && (LA(2) == OP_LBRACE || LA(2) == OP_DOT) && (_tokenSet_43.member(LA(3)))) {
				languageSpecList();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else if ((_tokenSet_24.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
		}
		else if ((LA(1) == IDENT) && (LA(2) == OP_LBRACE || LA(2) == OP_DOT) && (_tokenSet_43.member(LA(3)))) {
			languageSpec();
			astFactory->addASTChild( currentAST, returnAST );
			{
			if ((LA(1) == OP_SEMI) && (LA(2) == IDENT) && (LA(3) == OP_LBRACE || LA(3) == OP_DOT)) {
				match(OP_SEMI);
				languageSpecList();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else if ((_tokenSet_24.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			{
			if ((LA(1) == OP_SEMI) && (_tokenSet_24.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
				match(OP_SEMI);
			}
			else if ((_tokenSet_24.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		languageSpecList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_24);
	}
	returnAST = languageSpecList_AST;
}

void GrpParser::languageSpec() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST languageSpec_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  I = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST I_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		I = LT(1);
		I_AST = astFactory->create(I);
		match(IDENT);
		{
		switch ( LA(1)) {
		case OP_DOT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp167_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp167_AST = astFactory->create(LT(1));
			match(OP_DOT);
			languageSpecItem();
			X1_AST = returnAST;
			languageSpec_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 379 "GrpParser.g"
			languageSpec_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(astFactory->create(ZdotStruct))->add(I_AST)->add(X1_AST)));
#line 4293 "GrpParser.cpp"
			currentAST.root = languageSpec_AST;
			if ( languageSpec_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				languageSpec_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = languageSpec_AST->getFirstChild();
			else
				currentAST.child = languageSpec_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		case OP_LBRACE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp168_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp168_AST = astFactory->create(LT(1));
			match(OP_LBRACE);
			languageItemList();
			X2_AST = returnAST;
			match(OP_RBRACE);
			{
			if ((LA(1) == OP_SEMI) && (_tokenSet_24.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
				match(OP_SEMI);
			}
			else if ((_tokenSet_24.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			languageSpec_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 381 "GrpParser.g"
			languageSpec_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(astFactory->create(ZdotStruct))->add(I_AST)->add(X2_AST)));
#line 4325 "GrpParser.cpp"
			currentAST.root = languageSpec_AST;
			if ( languageSpec_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				languageSpec_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = languageSpec_AST->getFirstChild();
			else
				currentAST.child = languageSpec_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_24);
	}
	returnAST = languageSpec_AST;
}

void GrpParser::languageSpecItem() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST languageSpecItem_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  I = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST I_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  E1 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST E1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST Vi1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  Vi2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST Vi2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  Ilang = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST Ilang_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  Ilangs = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST Ilangs_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  E2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST E2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST LL_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case IDENT:
		{
			I = LT(1);
			I_AST = astFactory->create(I);
			match(IDENT);
			E1 = LT(1);
			E1_AST = astFactory->create(E1);
			match(OP_EQ);
			{
			switch ( LA(1)) {
			case LIT_INT:
			case OP_PLUS:
			case OP_MINUS:
			case LITERAL_true:
			case LITERAL_false:
			{
				signedInt();
				Vi1_AST = returnAST;
				break;
			}
			case IDENT:
			{
				Vi2 = LT(1);
				Vi2_AST = astFactory->create(Vi2);
				match(IDENT);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			languageSpecItem_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 391 "GrpParser.g"
			languageSpecItem_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(4))->add(E1_AST)->add(I_AST)->add(Vi1_AST)->add(Vi2_AST)));
#line 4407 "GrpParser.cpp"
			currentAST.root = languageSpecItem_AST;
			if ( languageSpecItem_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				languageSpecItem_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = languageSpecItem_AST->getFirstChild();
			else
				currentAST.child = languageSpecItem_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		case LITERAL_language:
		case LITERAL_languages:
		{
			{
			switch ( LA(1)) {
			case LITERAL_language:
			{
				Ilang = LT(1);
				Ilang_AST = astFactory->create(Ilang);
				match(LITERAL_language);
				break;
			}
			case LITERAL_languages:
			{
				Ilangs = LT(1);
				Ilangs_AST = astFactory->create(Ilangs);
				match(LITERAL_languages);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			E2 = LT(1);
			E2_AST = astFactory->create(E2);
			match(OP_EQ);
			languageCodeList();
			LL_AST = returnAST;
			languageSpecItem_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 395 "GrpParser.g"
			languageSpecItem_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(4))->add(E2_AST)->add(Ilang_AST)->add(Ilangs_AST)->add(LL_AST)));
#line 4450 "GrpParser.cpp"
			currentAST.root = languageSpecItem_AST;
			if ( languageSpecItem_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				languageSpecItem_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = languageSpecItem_AST->getFirstChild();
			else
				currentAST.child = languageSpecItem_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		if ((LA(1) == OP_SEMI) && (_tokenSet_44.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			match(OP_SEMI);
		}
		else if ((_tokenSet_44.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_44);
	}
	returnAST = languageSpecItem_AST;
}

void GrpParser::languageItemList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST languageItemList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == IDENT || LA(1) == LITERAL_language || LA(1) == LITERAL_languages)) {
				languageSpecItem();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop173;
			}
			
		}
		_loop173:;
		} // ( ... )*
		languageItemList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_45);
	}
	returnAST = languageItemList_AST;
}

void GrpParser::languageCodeList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST languageCodeList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LIT_STRING:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp172_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp172_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp172_AST);
			match(LIT_STRING);
			break;
		}
		case OP_LPAREN:
		{
			match(OP_LPAREN);
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp174_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp174_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp174_AST);
			match(LIT_STRING);
			{ // ( ... )*
			for (;;) {
				if ((LA(1) == OP_COMMA)) {
					match(OP_COMMA);
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp176_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
					tmp176_AST = astFactory->create(LT(1));
					astFactory->addASTChild(currentAST, tmp176_AST);
					match(LIT_STRING);
				}
				else {
					goto _loop182;
				}
				
			}
			_loop182:;
			} // ( ... )*
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp177_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp177_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp177_AST);
			match(OP_RPAREN);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		languageCodeList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_44);
	}
	returnAST = languageCodeList_AST;
}

void GrpParser::subEntry() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subEntry_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LITERAL_if:
		{
			subIf();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_LPAREN:
		case IDENT:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			subRule();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_pass:
		{
			subPass();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_environment:
		{
			subEnv();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_table:
		{
			tableDecl();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		subEntry_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_46);
	}
	returnAST = subEntry_AST;
}

void GrpParser::subIf() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subIf_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  C1k = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST C1k_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST E_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C1x_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C2x_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C3_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  C3k = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST C3k_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C3x_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		C1k = LT(1);
		C1k_AST = astFactory->create(C1k);
		match(LITERAL_if);
		match(OP_LPAREN);
		expr();
		E_AST = returnAST;
		match(OP_RPAREN);
		{
		subEntryList();
		C1x_AST = returnAST;
#line 430 "GrpParser.g"
		C1_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(C1k_AST)->add(E_AST)->add(C1x_AST)));
#line 4666 "GrpParser.cpp"
		}
		{
		if (((LA(1) >= LITERAL_else && LA(1) <= LITERAL_elseif)) && (_tokenSet_47.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			subElseIfList();
			C2x_AST = returnAST;
#line 431 "GrpParser.g"
			C2_AST = C2x_AST;
#line 4674 "GrpParser.cpp"
		}
		else if ((LA(1) == LITERAL_else || LA(1) == LITERAL_endif) && (_tokenSet_47.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		{
		switch ( LA(1)) {
		case LITERAL_else:
		{
			C3k = LT(1);
			C3k_AST = astFactory->create(C3k);
			match(LITERAL_else);
			subEntryList();
			C3x_AST = returnAST;
#line 432 "GrpParser.g"
			C3_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(C3k_AST)->add(C3x_AST)));
#line 4694 "GrpParser.cpp"
			break;
		}
		case LITERAL_endif:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(LITERAL_endif);
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_endpass:
		case LITERAL_if:
		case LITERAL_else:
		case LITERAL_endif:
		case Zelseif:
		case LITERAL_elseif:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		subIf_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 435 "GrpParser.g"
		subIf_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(4))->add(astFactory->create(ZifStruct))->add(C1_AST)->add(C2_AST)->add(C3_AST)));
#line 4750 "GrpParser.cpp"
		currentAST.root = subIf_AST;
		if ( subIf_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			subIf_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = subIf_AST->getFirstChild();
		else
			currentAST.child = subIf_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_46);
	}
	returnAST = subIf_AST;
}

void GrpParser::subRule() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subRule_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST L_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST L1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST R_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST R1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		subLhs();
		L1_AST = returnAST;
#line 448 "GrpParser.g"
		L_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zlhs))->add(L1_AST)));
#line 4783 "GrpParser.cpp"
		}
		{
		switch ( LA(1)) {
		case OP_GT:
		{
			match(OP_GT);
			{
			subRhs();
			R1_AST = returnAST;
#line 450 "GrpParser.g"
			R_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zrhs))->add(R1_AST)));
#line 4795 "GrpParser.cpp"
			}
			break;
		}
		case OP_SEMI:
		case OP_DIV:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_DIV:
		{
			match(OP_DIV);
			{
			context();
			C1_AST = returnAST;
#line 452 "GrpParser.g"
			C_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zcontext))->add(C1_AST)));
#line 4820 "GrpParser.cpp"
			}
			break;
		}
		case OP_SEMI:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_SEMI);
		subRule_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 454 "GrpParser.g"
		subRule_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(4))->add(astFactory->create(Zrule))->add(L_AST)->add(R_AST)->add(C_AST)));
#line 4838 "GrpParser.cpp"
		currentAST.root = subRule_AST;
		if ( subRule_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			subRule_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = subRule_AST->getFirstChild();
		else
			currentAST.child = subRule_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_46);
	}
	returnAST = subRule_AST;
}

void GrpParser::subPass() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subPass_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp185_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp185_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp185_AST);
		match(LITERAL_pass);
		match(OP_LPAREN);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp187_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp187_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp187_AST);
		match(LIT_INT);
		match(OP_RPAREN);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_LPAREN:
		case OP_SEMI:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_endpass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_endpass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_12.member(LA(1)))) {
				subEntry();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop200;
			}
			
		}
		_loop200:;
		} // ( ... )*
		match(LITERAL_endpass);
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_endpass:
		case LITERAL_if:
		case LITERAL_else:
		case LITERAL_endif:
		case Zelseif:
		case LITERAL_elseif:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		subPass_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_46);
	}
	returnAST = subPass_AST;
}

void GrpParser::subEnv() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subEnv_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp192_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp192_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp192_AST);
		match(LITERAL_environment);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_LPAREN:
		case OP_SEMI:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_12.member(LA(1)))) {
				subEntry();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop194;
			}
			
		}
		_loop194:;
		} // ( ... )*
		match(LITERAL_endenvironment);
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_endpass:
		case LITERAL_if:
		case LITERAL_else:
		case LITERAL_endif:
		case Zelseif:
		case LITERAL_elseif:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		subEnv_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_46);
	}
	returnAST = subEnv_AST;
}

void GrpParser::subEntryList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subEntryList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_12.member(LA(1)))) {
				subEntry();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop214;
			}
			
		}
		_loop214:;
		} // ( ... )*
		subEntryList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_48);
	}
	returnAST = subEntryList_AST;
}

void GrpParser::subElseIfList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subElseIfList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == Zelseif || LA(1) == LITERAL_elseif)) {
				subElseIf();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop209;
			}
			
		}
		_loop209:;
		} // ( ... )*
		subElseIfList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_49);
	}
	returnAST = subElseIfList_AST;
}

void GrpParser::subElseIf() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subElseIf_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case Zelseif:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp196_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp196_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp196_AST);
			match(Zelseif);
			break;
		}
		case LITERAL_elseif:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp197_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp197_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp197_AST);
			match(LITERAL_elseif);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_LPAREN);
		expr();
		astFactory->addASTChild( currentAST, returnAST );
		match(OP_RPAREN);
		subEntryList();
		astFactory->addASTChild( currentAST, returnAST );
		subElseIf_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_48);
	}
	returnAST = subElseIf_AST;
}

void GrpParser::subLhs() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subLhs_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{ // ( ... )+
		int _cnt223=0;
		for (;;) {
			if ((_tokenSet_50.member(LA(1))) && (_tokenSet_51.member(LA(2))) && (_tokenSet_52.member(LA(3)))) {
				subLhsRange();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				if ( _cnt223>=1 ) { goto _loop223; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
			}
			
			_cnt223++;
		}
		_loop223:;
		}  // ( ... )+
		subLhs_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_53);
	}
	returnAST = subLhs_AST;
}

void GrpParser::subRhs() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subRhs_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{ // ( ... )+
		int _cnt234=0;
		for (;;) {
			if ((_tokenSet_54.member(LA(1)))) {
				subRhsItem();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				if ( _cnt234>=1 ) { goto _loop234; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
			}
			
			_cnt234++;
		}
		_loop234:;
		}  // ( ... )+
		subRhs_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_55);
	}
	returnAST = subRhs_AST;
}

void GrpParser::context() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST context_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_56.member(LA(1)))) {
				contextRange();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop322;
			}
			
		}
		_loop322:;
		} // ( ... )*
		context_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_57);
	}
	returnAST = context_AST;
}

void GrpParser::subLhsRange() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subLhsRange_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  Q = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST Q_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case OP_LBRACKET:
		{
			subLhsList();
			X1_AST = returnAST;
			subLhsRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 460 "GrpParser.g"
			subLhsRange_AST = X1_AST;
#line 5348 "GrpParser.cpp"
			currentAST.root = subLhsRange_AST;
			if ( subLhsRange_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				subLhsRange_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = subLhsRange_AST->getFirstChild();
			else
				currentAST.child = subLhsRange_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		case OP_LPAREN:
		case IDENT:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			subLhsItem();
			X2_AST = returnAST;
			{
			if ((LA(1) == OP_QUESTION)) {
				Q = LT(1);
				Q_AST = astFactory->create(Q);
				match(OP_QUESTION);
				subLhsRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 462 "GrpParser.g"
				subLhsRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(Q_AST)->add(X2_AST)));
#line 5380 "GrpParser.cpp"
				currentAST.root = subLhsRange_AST;
				if ( subLhsRange_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
					subLhsRange_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
					  currentAST.child = subLhsRange_AST->getFirstChild();
				else
					currentAST.child = subLhsRange_AST;
				currentAST.advanceChildToEnd();
			}
			else if ((_tokenSet_53.member(LA(1))) && (_tokenSet_58.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
				subLhsRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 463 "GrpParser.g"
				subLhsRange_AST = X2_AST;
#line 5393 "GrpParser.cpp"
				currentAST.root = subLhsRange_AST;
				if ( subLhsRange_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
					subLhsRange_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
					  currentAST.child = subLhsRange_AST->getFirstChild();
				else
					currentAST.child = subLhsRange_AST;
				currentAST.advanceChildToEnd();
			}
			else if ((_tokenSet_53.member(LA(1))) && (_tokenSet_58.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_53);
	}
	returnAST = subLhsRange_AST;
}

void GrpParser::subLhsList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subLhsList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		match(OP_LBRACKET);
		{ // ( ... )+
		int _cnt230=0;
		for (;;) {
			if ((_tokenSet_50.member(LA(1)))) {
				subLhs();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				if ( _cnt230>=1 ) { goto _loop230; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
			}
			
			_cnt230++;
		}
		_loop230:;
		}  // ( ... )+
		match(OP_RBRACKET);
		}
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp202_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp202_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp202_AST);
		match(OP_QUESTION);
		subLhsList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_53);
	}
	returnAST = subLhsList_AST;
}

void GrpParser::subLhsItem() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subLhsItem_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		subRhsItem();
		astFactory->addASTChild( currentAST, returnAST );
		subLhsItem_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_59);
	}
	returnAST = subLhsItem_AST;
}

void GrpParser::subRhsItem() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST subRhsItem_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  C1g = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST C1g_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  C2at = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST C2at_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C2s_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C2a_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  C3at = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST C3at_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C3s_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C4g1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  C4g2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST C4g2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C4a1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C4s1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C4s2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C4a2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST A_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case OP_UNDER:
		{
			C1g = LT(1);
			C1g_AST = astFactory->create(C1g);
			match(OP_UNDER);
			break;
		}
		case OP_LPAREN:
		case IDENT:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case OP_HASH:
		{
			{
			{
			switch ( LA(1)) {
			case OP_LPAREN:
			case IDENT:
			case LITERAL_pseudo:
			case LIT_UHEX:
			case LITERAL_codepoint:
			case LITERAL_glyphid:
			case LITERAL_postscript:
			case LITERAL_unicode:
			{
				glyphSpec();
				C4g1_AST = returnAST;
				break;
			}
			case OP_HASH:
			{
				C4g2 = LT(1);
				C4g2_AST = astFactory->create(C4g2);
				match(OP_HASH);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case OP_COLON:
			{
				{
				match(OP_COLON);
				associations();
				C4a1_AST = returnAST;
				{
				switch ( LA(1)) {
				case OP_DOLLAR:
				{
					match(OP_DOLLAR);
					selector();
					C4s1_AST = returnAST;
					break;
				}
				case OP_EQ:
				case OP_LPAREN:
				case OP_SEMI:
				case OP_LBRACE:
				case IDENT:
				case LITERAL_pseudo:
				case LIT_UHEX:
				case LITERAL_codepoint:
				case LITERAL_glyphid:
				case LITERAL_postscript:
				case LITERAL_unicode:
				case OP_GT:
				case OP_DIV:
				case OP_QUESTION:
				case OP_LBRACKET:
				case OP_RBRACKET:
				case OP_UNDER:
				case OP_AT:
				case OP_HASH:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				}
				break;
			}
			case OP_DOLLAR:
			{
				{
				match(OP_DOLLAR);
				selector();
				C4s2_AST = returnAST;
				{
				switch ( LA(1)) {
				case OP_COLON:
				{
					match(OP_COLON);
					associations();
					C4a2_AST = returnAST;
					break;
				}
				case OP_EQ:
				case OP_LPAREN:
				case OP_SEMI:
				case OP_LBRACE:
				case IDENT:
				case LITERAL_pseudo:
				case LIT_UHEX:
				case LITERAL_codepoint:
				case LITERAL_glyphid:
				case LITERAL_postscript:
				case LITERAL_unicode:
				case OP_GT:
				case OP_DIV:
				case OP_QUESTION:
				case OP_LBRACKET:
				case OP_RBRACKET:
				case OP_UNDER:
				case OP_AT:
				case OP_HASH:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				}
				break;
			}
			case OP_EQ:
			case OP_LPAREN:
			case OP_SEMI:
			case OP_LBRACE:
			case IDENT:
			case LITERAL_pseudo:
			case LIT_UHEX:
			case LITERAL_codepoint:
			case LITERAL_glyphid:
			case LITERAL_postscript:
			case LITERAL_unicode:
			case OP_GT:
			case OP_DIV:
			case OP_QUESTION:
			case OP_LBRACKET:
			case OP_RBRACKET:
			case OP_UNDER:
			case OP_AT:
			case OP_HASH:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			}
			break;
		}
		default:
			if ((LA(1) == OP_AT) && (LA(2) == LIT_INT || LA(2) == Qalias) && (_tokenSet_60.member(LA(3)))) {
				{
				C2at = LT(1);
				C2at_AST = astFactory->create(C2at);
				match(OP_AT);
				selectorAfterAt();
				C2s_AST = returnAST;
				{
				switch ( LA(1)) {
				case OP_COLON:
				{
					match(OP_COLON);
					associations();
					C2a_AST = returnAST;
					break;
				}
				case OP_EQ:
				case OP_LPAREN:
				case OP_SEMI:
				case OP_LBRACE:
				case IDENT:
				case LITERAL_pseudo:
				case LIT_UHEX:
				case LITERAL_codepoint:
				case LITERAL_glyphid:
				case LITERAL_postscript:
				case LITERAL_unicode:
				case OP_GT:
				case OP_DIV:
				case OP_QUESTION:
				case OP_LBRACKET:
				case OP_RBRACKET:
				case OP_UNDER:
				case OP_AT:
				case OP_HASH:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				}
			}
			else if ((LA(1) == OP_AT) && (_tokenSet_61.member(LA(2))) && (_tokenSet_62.member(LA(3)))) {
				{
				C3at = LT(1);
				C3at_AST = astFactory->create(C3at);
				match(OP_AT);
				{
				switch ( LA(1)) {
				case OP_COLON:
				{
					match(OP_COLON);
					break;
				}
				case OP_EQ:
				case OP_LPAREN:
				case OP_SEMI:
				case OP_LBRACE:
				case IDENT:
				case LIT_INT:
				case LITERAL_pseudo:
				case LIT_UHEX:
				case LITERAL_codepoint:
				case LITERAL_glyphid:
				case LITERAL_postscript:
				case LITERAL_unicode:
				case OP_GT:
				case OP_DIV:
				case OP_QUESTION:
				case OP_LBRACKET:
				case OP_RBRACKET:
				case OP_UNDER:
				case OP_AT:
				case OP_HASH:
				case Qalias:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				{
				switch ( LA(1)) {
				case LIT_INT:
				case Qalias:
				{
					selectorAfterAt();
					C3s_AST = returnAST;
					break;
				}
				case OP_EQ:
				case OP_LPAREN:
				case OP_SEMI:
				case OP_LBRACE:
				case IDENT:
				case LITERAL_pseudo:
				case LIT_UHEX:
				case LITERAL_codepoint:
				case LITERAL_glyphid:
				case LITERAL_postscript:
				case LITERAL_unicode:
				case OP_GT:
				case OP_DIV:
				case OP_QUESTION:
				case OP_LBRACKET:
				case OP_RBRACKET:
				case OP_UNDER:
				case OP_AT:
				case OP_HASH:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				}
			}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_EQ:
		{
			alias();
			A_AST = returnAST;
			break;
		}
		case OP_LPAREN:
		case OP_SEMI:
		case OP_LBRACE:
		case IDENT:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case OP_GT:
		case OP_DIV:
		case OP_QUESTION:
		case OP_LBRACKET:
		case OP_RBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		if ((_tokenSet_63.member(LA(1))) && (_tokenSet_62.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			attributes();
			X_AST = returnAST;
		}
		else if ((_tokenSet_59.member(LA(1))) && (_tokenSet_58.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		subRhsItem_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 497 "GrpParser.g"
		subRhsItem_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(15))->add(astFactory->create(ZruleItem))->add(C1g_AST)->add(C2at_AST)->add(C2s_AST)->add(C3at_AST)->add(C3s_AST)->add(C4g1_AST)->add(C4g2_AST)->add(C4s1_AST)->add(C4s2_AST)->add(A_AST)->add(C2a_AST)->add(C4a1_AST)->add(C4a2_AST)->add(X_AST)));
#line 5860 "GrpParser.cpp"
		currentAST.root = subRhsItem_AST;
		if ( subRhsItem_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			subRhsItem_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = subRhsItem_AST->getFirstChild();
		else
			currentAST.child = subRhsItem_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_59);
	}
	returnAST = subRhsItem_AST;
}

void GrpParser::selectorAfterAt() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST selectorAfterAt_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		slotIndicatorAfterAt();
		X_AST = returnAST;
		selectorAfterAt_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 528 "GrpParser.g"
		selectorAfterAt_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zselector))->add(X_AST)));
#line 5888 "GrpParser.cpp"
		currentAST.root = selectorAfterAt_AST;
		if ( selectorAfterAt_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			selectorAfterAt_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = selectorAfterAt_AST->getFirstChild();
		else
			currentAST.child = selectorAfterAt_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_60);
	}
	returnAST = selectorAfterAt_AST;
}

void GrpParser::associations() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST associations_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST S1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST S2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case IDENT:
		case LIT_INT:
		case Qalias:
		{
			slotIndicator();
			S1_AST = returnAST;
			break;
		}
		case OP_LPAREN:
		{
			assocsList();
			S2_AST = returnAST;
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		associations_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 513 "GrpParser.g"
		associations_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(astFactory->create(Zassocs))->add(S1_AST)->add(S2_AST)));
#line 5937 "GrpParser.cpp"
		currentAST.root = associations_AST;
		if ( associations_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			associations_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = associations_AST->getFirstChild();
		else
			currentAST.child = associations_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_64);
	}
	returnAST = associations_AST;
}

void GrpParser::selector() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST selector_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		slotIndicator();
		X_AST = returnAST;
		selector_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 508 "GrpParser.g"
		selector_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zselector))->add(X_AST)));
#line 5965 "GrpParser.cpp"
		currentAST.root = selector_AST;
		if ( selector_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			selector_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = selector_AST->getFirstChild();
		else
			currentAST.child = selector_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_60);
	}
	returnAST = selector_AST;
}

void GrpParser::alias() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST alias_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  I = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST I_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp209_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp209_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp209_AST);
		match(OP_EQ);
		I = LT(1);
		I_AST = astFactory->create(I);
		astFactory->addASTChild(currentAST, I_AST);
		match(IDENT);
		alias_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 649 "GrpParser.g"
		alias_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zalias))->add(I_AST)));
#line 6000 "GrpParser.cpp"
		currentAST.root = alias_AST;
		if ( alias_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			alias_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = alias_AST->getFirstChild();
		else
			currentAST.child = alias_AST;
		currentAST.advanceChildToEnd();
		alias_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_65);
	}
	returnAST = alias_AST;
}

void GrpParser::slotIndicator() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST slotIndicator_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LIT_INT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp210_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp210_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp210_AST);
			match(LIT_INT);
			break;
		}
		case IDENT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp211_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp211_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp211_AST);
			match(IDENT);
			break;
		}
		case Qalias:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp212_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp212_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp212_AST);
			match(Qalias);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		slotIndicator_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_66);
	}
	returnAST = slotIndicator_AST;
}

void GrpParser::assocsList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST assocsList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		match(OP_LPAREN);
		{
		switch ( LA(1)) {
		case IDENT:
		case LIT_INT:
		case Qalias:
		{
			slotIndicator();
			astFactory->addASTChild( currentAST, returnAST );
			{ // ( ... )*
			for (;;) {
				if ((_tokenSet_67.member(LA(1)))) {
					{
					switch ( LA(1)) {
					case OP_COMMA:
					{
						match(OP_COMMA);
						break;
					}
					case IDENT:
					case LIT_INT:
					case Qalias:
					{
						break;
					}
					default:
					{
						throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
					}
					}
					}
					slotIndicator();
					astFactory->addASTChild( currentAST, returnAST );
				}
				else {
					goto _loop259;
				}
				
			}
			_loop259:;
			} // ( ... )*
			break;
		}
		case OP_RPAREN:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_RPAREN);
		}
		assocsList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_64);
	}
	returnAST = assocsList_AST;
}

void GrpParser::slotIndicatorAfterAt() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST slotIndicatorAfterAt_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LIT_INT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp216_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp216_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp216_AST);
			match(LIT_INT);
			break;
		}
		case Qalias:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp217_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp217_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp217_AST);
			match(Qalias);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		slotIndicatorAfterAt_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_60);
	}
	returnAST = slotIndicatorAfterAt_AST;
}

void GrpParser::posEntry() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST posEntry_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LITERAL_if:
		{
			posIf();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_LPAREN:
		case IDENT:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			posRule();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_pass:
		{
			posPass();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_environment:
		{
			posEnv();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LITERAL_table:
		{
			tableDecl();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		posEntry_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_46);
	}
	returnAST = posEntry_AST;
}

void GrpParser::posIf() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST posIf_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  C1k = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST C1k_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST E_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C1x_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C2x_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C3_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  C3k = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST C3k_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C3x_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		C1k = LT(1);
		C1k_AST = astFactory->create(C1k);
		match(LITERAL_if);
		match(OP_LPAREN);
		expr();
		E_AST = returnAST;
		match(OP_RPAREN);
		{
		posEntryList();
		C1x_AST = returnAST;
#line 565 "GrpParser.g"
		C1_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(C1k_AST)->add(E_AST)->add(C1x_AST)));
#line 6267 "GrpParser.cpp"
		}
		{
		if (((LA(1) >= LITERAL_else && LA(1) <= LITERAL_elseif)) && (_tokenSet_47.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			posElseIfList();
			C2x_AST = returnAST;
#line 566 "GrpParser.g"
			C2_AST = C2x_AST;
#line 6275 "GrpParser.cpp"
		}
		else if ((LA(1) == LITERAL_else || LA(1) == LITERAL_endif) && (_tokenSet_47.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		{
		switch ( LA(1)) {
		case LITERAL_else:
		{
			C3k = LT(1);
			C3k_AST = astFactory->create(C3k);
			match(LITERAL_else);
			posEntryList();
			C3x_AST = returnAST;
#line 567 "GrpParser.g"
			C3_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(C3k_AST)->add(C3x_AST)));
#line 6295 "GrpParser.cpp"
			break;
		}
		case LITERAL_endif:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(LITERAL_endif);
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_endpass:
		case LITERAL_if:
		case LITERAL_else:
		case LITERAL_endif:
		case Zelseif:
		case LITERAL_elseif:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		posIf_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 570 "GrpParser.g"
		posIf_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(4))->add(astFactory->create(ZifStruct))->add(C1_AST)->add(C2_AST)->add(C3_AST)));
#line 6351 "GrpParser.cpp"
		currentAST.root = posIf_AST;
		if ( posIf_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			posIf_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = posIf_AST->getFirstChild();
		else
			currentAST.child = posIf_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_46);
	}
	returnAST = posIf_AST;
}

void GrpParser::posRule() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST posRule_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		subRule();
		astFactory->addASTChild( currentAST, returnAST );
		posRule_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_46);
	}
	returnAST = posRule_AST;
}

void GrpParser::posPass() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST posPass_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp222_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp222_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp222_AST);
		match(LITERAL_pass);
		match(OP_LPAREN);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp224_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp224_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp224_AST);
		match(LIT_INT);
		match(OP_RPAREN);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_LPAREN:
		case OP_SEMI:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_endpass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_endpass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_12.member(LA(1)))) {
				posEntry();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop288;
			}
			
		}
		_loop288:;
		} // ( ... )*
		match(LITERAL_endpass);
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_endpass:
		case LITERAL_if:
		case LITERAL_else:
		case LITERAL_endif:
		case Zelseif:
		case LITERAL_elseif:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		posPass_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_46);
	}
	returnAST = posPass_AST;
}

void GrpParser::posEnv() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST posEnv_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp229_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp229_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp229_AST);
		match(LITERAL_environment);
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			directives();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_LPAREN:
		case OP_SEMI:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_if:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_12.member(LA(1)))) {
				posEntry();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop282;
			}
			
		}
		_loop282:;
		} // ( ... )*
		match(LITERAL_endenvironment);
		{
		switch ( LA(1)) {
		case OP_SEMI:
		{
			match(OP_SEMI);
			break;
		}
		case OP_LPAREN:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case LITERAL_pass:
		case LITERAL_endpass:
		case LITERAL_if:
		case LITERAL_else:
		case LITERAL_endif:
		case Zelseif:
		case LITERAL_elseif:
		case OP_LBRACKET:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		posEnv_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_46);
	}
	returnAST = posEnv_AST;
}

void GrpParser::posEntryList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST posEntryList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_12.member(LA(1)))) {
				posEntry();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop302;
			}
			
		}
		_loop302:;
		} // ( ... )*
		posEntryList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_48);
	}
	returnAST = posEntryList_AST;
}

void GrpParser::posElseIfList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST posElseIfList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == Zelseif || LA(1) == LITERAL_elseif)) {
				posElseIf();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop297;
			}
			
		}
		_loop297:;
		} // ( ... )*
		posElseIfList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_49);
	}
	returnAST = posElseIfList_AST;
}

void GrpParser::posElseIf() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST posElseIf_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case Zelseif:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp233_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp233_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp233_AST);
			match(Zelseif);
			break;
		}
		case LITERAL_elseif:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp234_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp234_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp234_AST);
			match(LITERAL_elseif);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_LPAREN);
		expr();
		astFactory->addASTChild( currentAST, returnAST );
		match(OP_RPAREN);
		posEntryList();
		astFactory->addASTChild( currentAST, returnAST );
		posElseIf_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_48);
	}
	returnAST = posElseIf_AST;
}

void GrpParser::posRhs() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST posRhs_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{ // ( ... )+
		int _cnt306=0;
		for (;;) {
			if ((_tokenSet_50.member(LA(1))) && (_tokenSet_68.member(LA(2))) && (_tokenSet_69.member(LA(3)))) {
				posRhsRange();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				if ( _cnt306>=1 ) { goto _loop306; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
			}
			
			_cnt306++;
		}
		_loop306:;
		}  // ( ... )+
		posRhs_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_70);
	}
	returnAST = posRhs_AST;
}

void GrpParser::posRhsRange() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST posRhsRange_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  Q = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST Q_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case OP_LBRACKET:
		{
			posRhsList();
			X1_AST = returnAST;
			posRhsRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 593 "GrpParser.g"
			posRhsRange_AST = X1_AST;
#line 6820 "GrpParser.cpp"
			currentAST.root = posRhsRange_AST;
			if ( posRhsRange_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				posRhsRange_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = posRhsRange_AST->getFirstChild();
			else
				currentAST.child = posRhsRange_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		case OP_LPAREN:
		case IDENT:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case OP_UNDER:
		case OP_AT:
		case OP_HASH:
		{
			posRhsItem();
			X2_AST = returnAST;
			{
			if ((LA(1) == OP_QUESTION)) {
				Q = LT(1);
				Q_AST = astFactory->create(Q);
				match(OP_QUESTION);
				posRhsRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 595 "GrpParser.g"
				posRhsRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(Q_AST)->add(X2_AST)));
#line 6852 "GrpParser.cpp"
				currentAST.root = posRhsRange_AST;
				if ( posRhsRange_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
					posRhsRange_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
					  currentAST.child = posRhsRange_AST->getFirstChild();
				else
					currentAST.child = posRhsRange_AST;
				currentAST.advanceChildToEnd();
			}
			else if ((_tokenSet_70.member(LA(1))) && (_tokenSet_68.member(LA(2))) && (_tokenSet_69.member(LA(3)))) {
				posRhsRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 596 "GrpParser.g"
				posRhsRange_AST = X2_AST;
#line 6865 "GrpParser.cpp"
				currentAST.root = posRhsRange_AST;
				if ( posRhsRange_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
					posRhsRange_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
					  currentAST.child = posRhsRange_AST->getFirstChild();
				else
					currentAST.child = posRhsRange_AST;
				currentAST.advanceChildToEnd();
			}
			else if ((_tokenSet_70.member(LA(1))) && (_tokenSet_68.member(LA(2))) && (_tokenSet_69.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_70);
	}
	returnAST = posRhsRange_AST;
}

void GrpParser::posRhsList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST posRhsList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		match(OP_LBRACKET);
		{ // ( ... )+
		int _cnt313=0;
		for (;;) {
			if ((_tokenSet_50.member(LA(1)))) {
				posRhs();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				if ( _cnt313>=1 ) { goto _loop313; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
			}
			
			_cnt313++;
		}
		_loop313:;
		}  // ( ... )+
		match(OP_RBRACKET);
		}
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp239_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp239_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp239_AST);
		match(OP_QUESTION);
		posRhsList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_70);
	}
	returnAST = posRhsList_AST;
}

void GrpParser::posRhsItem() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST posRhsItem_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		subRhsItem();
		astFactory->addASTChild( currentAST, returnAST );
		posRhsItem_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_71);
	}
	returnAST = posRhsItem_AST;
}

void GrpParser::contextRange() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST contextRange_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  X2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST X2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X3_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  Q = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST Q_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		{
		switch ( LA(1)) {
		case OP_LBRACKET:
		{
			contextList();
			X1_AST = returnAST;
			contextRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 621 "GrpParser.g"
			contextRange_AST = X1_AST;
#line 6974 "GrpParser.cpp"
			currentAST.root = contextRange_AST;
			if ( contextRange_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				contextRange_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = contextRange_AST->getFirstChild();
			else
				currentAST.child = contextRange_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		case OP_CARET:
		{
			X2 = LT(1);
			X2_AST = astFactory->create(X2);
			match(OP_CARET);
			contextRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 622 "GrpParser.g"
			contextRange_AST = X2_AST;
#line 6992 "GrpParser.cpp"
			currentAST.root = contextRange_AST;
			if ( contextRange_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				contextRange_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = contextRange_AST->getFirstChild();
			else
				currentAST.child = contextRange_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		case OP_LPAREN:
		case IDENT:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case OP_UNDER:
		case OP_HASH:
		{
			contextItem();
			X3_AST = returnAST;
			{
			if ((LA(1) == OP_QUESTION)) {
				Q = LT(1);
				Q_AST = astFactory->create(Q);
				match(OP_QUESTION);
				contextRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 624 "GrpParser.g"
				contextRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(Q_AST)->add(X3_AST)));
#line 7023 "GrpParser.cpp"
				currentAST.root = contextRange_AST;
				if ( contextRange_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
					contextRange_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
					  currentAST.child = contextRange_AST->getFirstChild();
				else
					currentAST.child = contextRange_AST;
				currentAST.advanceChildToEnd();
			}
			else if ((_tokenSet_72.member(LA(1))) && (_tokenSet_73.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
				contextRange_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 625 "GrpParser.g"
				contextRange_AST = X3_AST;
#line 7036 "GrpParser.cpp"
				currentAST.root = contextRange_AST;
				if ( contextRange_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
					contextRange_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
					  currentAST.child = contextRange_AST->getFirstChild();
				else
					currentAST.child = contextRange_AST;
				currentAST.advanceChildToEnd();
			}
			else if ((_tokenSet_72.member(LA(1))) && (_tokenSet_73.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_72);
	}
	returnAST = contextRange_AST;
}

void GrpParser::contextList() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST contextList_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(OP_LBRACKET);
		{ // ( ... )+
		int _cnt329=0;
		for (;;) {
			if ((_tokenSet_56.member(LA(1)))) {
				contextRange();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				if ( _cnt329>=1 ) { goto _loop329; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
			}
			
			_cnt329++;
		}
		_loop329:;
		}  // ( ... )+
		match(OP_RBRACKET);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp242_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp242_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp242_AST);
		match(OP_QUESTION);
		contextList_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_72);
	}
	returnAST = contextList_AST;
}

void GrpParser::contextItem() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST contextItem_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  C1 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST C1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  C2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST C2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C3_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST A_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST Y_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case OP_HASH:
		{
			C1 = LT(1);
			C1_AST = astFactory->create(C1);
			match(OP_HASH);
			break;
		}
		case OP_UNDER:
		{
			C2 = LT(1);
			C2_AST = astFactory->create(C2);
			match(OP_UNDER);
			break;
		}
		case OP_LPAREN:
		case IDENT:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		{
			glyphSpec();
			C3_AST = returnAST;
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_EQ:
		{
			alias();
			A_AST = returnAST;
			break;
		}
		case OP_LPAREN:
		case OP_SEMI:
		case OP_LBRACE:
		case IDENT:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case OP_QUESTION:
		case OP_LBRACKET:
		case OP_RBRACKET:
		case OP_UNDER:
		case OP_HASH:
		case OP_CARET:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case OP_LBRACE:
		{
			constraint();
			Y_AST = returnAST;
			break;
		}
		case OP_LPAREN:
		case OP_SEMI:
		case IDENT:
		case LITERAL_pseudo:
		case LIT_UHEX:
		case LITERAL_codepoint:
		case LITERAL_glyphid:
		case LITERAL_postscript:
		case LITERAL_unicode:
		case OP_QUESTION:
		case OP_LBRACKET:
		case OP_RBRACKET:
		case OP_UNDER:
		case OP_HASH:
		case OP_CARET:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		contextItem_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 639 "GrpParser.g"
		contextItem_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(6))->add(astFactory->create(ZruleItem))->add(C1_AST)->add(C2_AST)->add(C3_AST)->add(A_AST)->add(Y_AST)));
#line 7221 "GrpParser.cpp"
		currentAST.root = contextItem_AST;
		if ( contextItem_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			contextItem_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = contextItem_AST->getFirstChild();
		else
			currentAST.child = contextItem_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_74);
	}
	returnAST = contextItem_AST;
}

void GrpParser::constraint() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST constraint_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(OP_LBRACE);
		{
		switch ( LA(1)) {
		case OP_LPAREN:
		case IDENT:
		case LIT_INT:
		case LIT_STRING:
		case LITERAL_glyph:
		case OP_AT:
		case LITERAL_position:
		case LITERAL_justify:
		case LITERAL_min:
		case LITERAL_max:
		case OP_PLUS:
		case OP_MINUS:
		case OP_NOT:
		case OP_BITNOT:
		case LITERAL_true:
		case LITERAL_false:
		{
			expr();
			X_AST = returnAST;
			break;
		}
		case OP_RBRACE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_RBRACE);
		constraint_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 644 "GrpParser.g"
		constraint_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zconstraint))->add(X_AST)));
#line 7282 "GrpParser.cpp"
		currentAST.root = constraint_AST;
		if ( constraint_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			constraint_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = constraint_AST->getFirstChild();
		else
			currentAST.child = constraint_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_74);
	}
	returnAST = constraint_AST;
}

void GrpParser::otherEntry() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST otherEntry_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST X_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		if ((_tokenSet_75.member(LA(1))) && ((LA(2) >= OP_EQ && LA(2) <= AT_IDENT)) && (_tokenSet_4.member(LA(3)))) {
			{
			match(_tokenSet_75);
			}
		}
		else if ((LA(1) == LITERAL_environment || LA(1) == LITERAL_table) && (_tokenSet_76.member(LA(2))) && ((LA(3) >= OP_EQ && LA(3) <= AT_IDENT))) {
			topDecl();
			X_AST = returnAST;
			otherEntry_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 660 "GrpParser.g"
			otherEntry_AST = X_AST;
#line 7317 "GrpParser.cpp"
			currentAST.root = otherEntry_AST;
			if ( otherEntry_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				otherEntry_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = otherEntry_AST->getFirstChild();
			else
				currentAST.child = otherEntry_AST;
			currentAST.advanceChildToEnd();
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_9);
	}
	returnAST = otherEntry_AST;
}

void GrpParser::attrName() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST attrName_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case IDENT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp246_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp246_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp246_AST);
			match(IDENT);
			break;
		}
		case LIT_INT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp247_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp247_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp247_AST);
			match(LIT_INT);
			break;
		}
		case LITERAL_glyph:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp248_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp248_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp248_AST);
			match(LITERAL_glyph);
			break;
		}
		case LITERAL_justify:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp249_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp249_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp249_AST);
			match(LITERAL_justify);
			break;
		}
		case LITERAL_min:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp250_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp250_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp250_AST);
			match(LITERAL_min);
			break;
		}
		case LITERAL_max:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp251_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp251_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp251_AST);
			match(LITERAL_max);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		attrName_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_30);
	}
	returnAST = attrName_AST;
}

void GrpParser::attrAssignOp() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST attrAssignOp_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case OP_EQ:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp252_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp252_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp252_AST);
			match(OP_EQ);
			break;
		}
		case OP_PLUSEQUAL:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp253_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp253_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp253_AST);
			match(OP_PLUSEQUAL);
			break;
		}
		case OP_MINUSEQUAL:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp254_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp254_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp254_AST);
			match(OP_MINUSEQUAL);
			break;
		}
		case OP_DIVEQUAL:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp255_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp255_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp255_AST);
			match(OP_DIVEQUAL);
			break;
		}
		case OP_MULTEQUAL:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp256_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp256_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp256_AST);
			match(OP_MULTEQUAL);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		attrAssignOp_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
	returnAST = attrAssignOp_AST;
}

void GrpParser::function() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST function_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  I = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST I_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST E_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		I = LT(1);
		I_AST = astFactory->create(I);
		match(IDENT);
		match(OP_LPAREN);
		{
		switch ( LA(1)) {
		case OP_LPAREN:
		case IDENT:
		case LIT_INT:
		case LIT_STRING:
		case LITERAL_glyph:
		case OP_AT:
		case LITERAL_position:
		case LITERAL_justify:
		case LITERAL_min:
		case LITERAL_max:
		case OP_PLUS:
		case OP_MINUS:
		case OP_NOT:
		case OP_BITNOT:
		case LITERAL_true:
		case LITERAL_false:
		{
			exprList();
			E_AST = returnAST;
			break;
		}
		case OP_RPAREN:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_RPAREN);
		function_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 822 "GrpParser.g"
		function_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(astFactory->create(Zfunction))->add(I_AST)->add(E_AST)));
#line 7523 "GrpParser.cpp"
		currentAST.root = function_AST;
		if ( function_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			function_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = function_AST->getFirstChild();
		else
			currentAST.child = function_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_34);
	}
	returnAST = function_AST;
}

void GrpParser::conditionalExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST conditionalExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		logicalOrExpr();
		astFactory->addASTChild( currentAST, returnAST );
		{
		switch ( LA(1)) {
		case OP_QUESTION:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp259_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp259_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp259_AST);
			match(OP_QUESTION);
			expr();
			astFactory->addASTChild( currentAST, returnAST );
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp260_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp260_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp260_AST);
			match(OP_COLON);
			expr();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE:
		case OP_RPAREN:
		case OP_SEMI:
		case LITERAL_environment:
		case LITERAL_endenvironment:
		case OP_RBRACE:
		case IDENT:
		case LITERAL_table:
		case LITERAL_endtable:
		case OP_COMMA:
		case LITERAL_glyph:
		case OP_COLON:
		case LITERAL_position:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		conditionalExpr_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_8);
	}
	returnAST = conditionalExpr_AST;
}

void GrpParser::logicalOrExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST logicalOrExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		logicalAndExpr();
		astFactory->addASTChild( currentAST, returnAST );
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == OP_OR)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp261_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp261_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp261_AST);
				match(OP_OR);
				logicalAndExpr();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop373;
			}
			
		}
		_loop373:;
		} // ( ... )*
		logicalOrExpr_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_77);
	}
	returnAST = logicalOrExpr_AST;
}

void GrpParser::logicalAndExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST logicalAndExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		bitwiseOrExpr();
		astFactory->addASTChild( currentAST, returnAST );
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == OP_AND)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp262_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp262_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp262_AST);
				match(OP_AND);
				bitwiseOrExpr();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop376;
			}
			
		}
		_loop376:;
		} // ( ... )*
		logicalAndExpr_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_78);
	}
	returnAST = logicalAndExpr_AST;
}

void GrpParser::bitwiseOrExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST bitwiseOrExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		bitwiseAndExpr();
		astFactory->addASTChild( currentAST, returnAST );
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == OP_BITOR)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp263_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp263_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp263_AST);
				match(OP_BITOR);
				bitwiseAndExpr();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop379;
			}
			
		}
		_loop379:;
		} // ( ... )*
		bitwiseOrExpr_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_79);
	}
	returnAST = bitwiseOrExpr_AST;
}

void GrpParser::bitwiseAndExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST bitwiseAndExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		comparativeExpr();
		astFactory->addASTChild( currentAST, returnAST );
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == OP_BITAND)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp264_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp264_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp264_AST);
				match(OP_BITAND);
				comparativeExpr();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop382;
			}
			
		}
		_loop382:;
		} // ( ... )*
		bitwiseAndExpr_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_80);
	}
	returnAST = bitwiseAndExpr_AST;
}

void GrpParser::comparativeExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST comparativeExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		additiveExpr();
		astFactory->addASTChild( currentAST, returnAST );
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_81.member(LA(1)))) {
				{
				switch ( LA(1)) {
				case OP_EQUALEQUAL:
				{
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp265_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
					tmp265_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, tmp265_AST);
					match(OP_EQUALEQUAL);
					break;
				}
				case OP_NE:
				{
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp266_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
					tmp266_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, tmp266_AST);
					match(OP_NE);
					break;
				}
				case OP_LT:
				{
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp267_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
					tmp267_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, tmp267_AST);
					match(OP_LT);
					break;
				}
				case OP_LE:
				{
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp268_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
					tmp268_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, tmp268_AST);
					match(OP_LE);
					break;
				}
				case OP_GT:
				{
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp269_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
					tmp269_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, tmp269_AST);
					match(OP_GT);
					break;
				}
				case OP_GE:
				{
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp270_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
					tmp270_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, tmp270_AST);
					match(OP_GE);
					break;
				}
				case OP_EQ:
				{
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp271_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
					tmp271_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, tmp271_AST);
					match(OP_EQ);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				additiveExpr();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop386;
			}
			
		}
		_loop386:;
		} // ( ... )*
		comparativeExpr_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_82);
	}
	returnAST = comparativeExpr_AST;
}

void GrpParser::additiveExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST additiveExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		multiplicativeExpr();
		astFactory->addASTChild( currentAST, returnAST );
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == OP_PLUS || LA(1) == OP_MINUS)) {
				{
				switch ( LA(1)) {
				case OP_PLUS:
				{
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp272_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
					tmp272_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, tmp272_AST);
					match(OP_PLUS);
					break;
				}
				case OP_MINUS:
				{
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp273_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
					tmp273_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, tmp273_AST);
					match(OP_MINUS);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				multiplicativeExpr();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop390;
			}
			
		}
		_loop390:;
		} // ( ... )*
		additiveExpr_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_83);
	}
	returnAST = additiveExpr_AST;
}

void GrpParser::multiplicativeExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST multiplicativeExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		unaryExpr();
		astFactory->addASTChild( currentAST, returnAST );
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == OP_DIV || LA(1) == OP_MULT)) {
				{
				switch ( LA(1)) {
				case OP_MULT:
				{
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp274_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
					tmp274_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, tmp274_AST);
					match(OP_MULT);
					break;
				}
				case OP_DIV:
				{
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp275_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
					tmp275_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, tmp275_AST);
					match(OP_DIV);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				unaryExpr();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop394;
			}
			
		}
		_loop394:;
		} // ( ... )*
		multiplicativeExpr_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_84);
	}
	returnAST = multiplicativeExpr_AST;
}

void GrpParser::unaryExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST unaryExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		if ((LA(1) == OP_MINUS || LA(1) == OP_NOT || LA(1) == OP_BITNOT) && (_tokenSet_85.member(LA(2))) && (_tokenSet_86.member(LA(3)))) {
			{
			{
			switch ( LA(1)) {
			case OP_NOT:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp276_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp276_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp276_AST);
				match(OP_NOT);
				break;
			}
			case OP_MINUS:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp277_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp277_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp277_AST);
				match(OP_MINUS);
				break;
			}
			case OP_BITNOT:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp278_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp278_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp278_AST);
				match(OP_BITNOT);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			singleExpr();
			astFactory->addASTChild( currentAST, returnAST );
			}
		}
		else if ((_tokenSet_85.member(LA(1))) && (_tokenSet_86.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
			singleExpr();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		unaryExpr_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_87);
	}
	returnAST = unaryExpr_AST;
}

void GrpParser::singleExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST singleExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case OP_LPAREN:
		{
			match(OP_LPAREN);
			expr();
			astFactory->addASTChild( currentAST, returnAST );
			match(OP_RPAREN);
			break;
		}
		case LIT_STRING:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp281_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp281_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp281_AST);
			match(LIT_STRING);
			break;
		}
		case LITERAL_min:
		case LITERAL_max:
		{
			arithFunction();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case IDENT:
		case LITERAL_glyph:
		case OP_AT:
		case LITERAL_position:
		case LITERAL_justify:
		{
			lookupExpr();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case LIT_INT:
		case OP_PLUS:
		case OP_MINUS:
		case LITERAL_true:
		case LITERAL_false:
		{
			signedInt();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		singleExpr_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_87);
	}
	returnAST = singleExpr_AST;
}

void GrpParser::arithFunction() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST arithFunction_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST E1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LITERAL_max:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp282_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp282_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp282_AST);
			match(LITERAL_max);
			break;
		}
		case LITERAL_min:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp283_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp283_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp283_AST);
			match(LITERAL_min);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_LPAREN);
		{
		switch ( LA(1)) {
		case OP_LPAREN:
		case IDENT:
		case LIT_INT:
		case LIT_STRING:
		case LITERAL_glyph:
		case OP_AT:
		case LITERAL_position:
		case LITERAL_justify:
		case LITERAL_min:
		case LITERAL_max:
		case OP_PLUS:
		case OP_MINUS:
		case OP_NOT:
		case OP_BITNOT:
		case LITERAL_true:
		case LITERAL_false:
		{
			exprList();
			E1_AST = returnAST;
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case OP_RPAREN:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(OP_RPAREN);
		arithFunction_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_87);
	}
	returnAST = arithFunction_AST;
}

void GrpParser::lookupExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST lookupExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST S_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST I1g_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST I1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST I3_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST I4_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C4_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST I2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST C2_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case OP_AT:
		{
			selectorExpr();
			S_AST = returnAST;
			{
			switch ( LA(1)) {
			case OP_DOT:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp286_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp286_AST = astFactory->create(LT(1));
				match(OP_DOT);
				{
				if ((LA(1) == LITERAL_glyph) && (LA(2) == OP_DOT) && (LA(3) == IDENT || LA(3) == LITERAL_glyph || LA(3) == LITERAL_position)) {
					glyphIdentDot();
					I1g_AST = returnAST;
				}
				else if ((LA(1) == IDENT || LA(1) == LITERAL_glyph || LA(1) == LITERAL_position) && (_tokenSet_88.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
					identDot();
					I1_AST = returnAST;
				}
				else {
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				
				}
				{
				switch ( LA(1)) {
				case OP_DOT:
				{
					clusterExpr();
					C1_AST = returnAST;
					break;
				}
				case ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE:
				case OP_EQ:
				case OP_RPAREN:
				case OP_SEMI:
				case LITERAL_environment:
				case LITERAL_endenvironment:
				case OP_RBRACE:
				case IDENT:
				case LITERAL_table:
				case LITERAL_endtable:
				case OP_COMMA:
				case LITERAL_glyph:
				case OP_GT:
				case OP_DIV:
				case OP_QUESTION:
				case OP_COLON:
				case LITERAL_position:
				case OP_OR:
				case OP_AND:
				case OP_BITOR:
				case OP_BITAND:
				case OP_EQUALEQUAL:
				case OP_NE:
				case OP_LT:
				case OP_LE:
				case OP_GE:
				case OP_PLUS:
				case OP_MINUS:
				case OP_MULT:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				lookupExpr_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 775 "GrpParser.g"
				lookupExpr_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(5))->add(astFactory->create(Zlookup))->add(S_AST)->add(I1_AST)->add(I1g_AST)->add(C1_AST)));
#line 8230 "GrpParser.cpp"
				currentAST.root = lookupExpr_AST;
				if ( lookupExpr_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
					lookupExpr_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
					  currentAST.child = lookupExpr_AST->getFirstChild();
				else
					currentAST.child = lookupExpr_AST;
				currentAST.advanceChildToEnd();
				break;
			}
			case ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE:
			case OP_EQ:
			case OP_RPAREN:
			case OP_SEMI:
			case LITERAL_environment:
			case LITERAL_endenvironment:
			case OP_RBRACE:
			case IDENT:
			case LITERAL_table:
			case LITERAL_endtable:
			case OP_COMMA:
			case LITERAL_glyph:
			case OP_GT:
			case OP_DIV:
			case OP_QUESTION:
			case OP_COLON:
			case LITERAL_position:
			case OP_OR:
			case OP_AND:
			case OP_BITOR:
			case OP_BITAND:
			case OP_EQUALEQUAL:
			case OP_NE:
			case OP_LT:
			case OP_LE:
			case OP_GE:
			case OP_PLUS:
			case OP_MINUS:
			case OP_MULT:
			{
				lookupExpr_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 776 "GrpParser.g"
				lookupExpr_AST = S_AST;
#line 8273 "GrpParser.cpp"
				currentAST.root = lookupExpr_AST;
				if ( lookupExpr_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
					lookupExpr_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
					  currentAST.child = lookupExpr_AST->getFirstChild();
				else
					currentAST.child = lookupExpr_AST;
				currentAST.advanceChildToEnd();
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case LITERAL_justify:
		{
			justifyIdentDot();
			I3_AST = returnAST;
			lookupExpr_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 779 "GrpParser.g"
			lookupExpr_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zlookup))->add(I3_AST)));
#line 8298 "GrpParser.cpp"
			currentAST.root = lookupExpr_AST;
			if ( lookupExpr_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
				lookupExpr_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
				  currentAST.child = lookupExpr_AST->getFirstChild();
			else
				currentAST.child = lookupExpr_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		default:
			if ((LA(1) == LITERAL_glyph) && (LA(2) == OP_DOT) && (LA(3) == IDENT || LA(3) == LITERAL_glyph || LA(3) == LITERAL_position)) {
				glyphIdentDot();
				I4_AST = returnAST;
				{
				switch ( LA(1)) {
				case OP_DOT:
				{
					clusterExpr();
					C4_AST = returnAST;
					break;
				}
				case ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE:
				case OP_EQ:
				case OP_RPAREN:
				case OP_SEMI:
				case LITERAL_environment:
				case LITERAL_endenvironment:
				case OP_RBRACE:
				case IDENT:
				case LITERAL_table:
				case LITERAL_endtable:
				case OP_COMMA:
				case LITERAL_glyph:
				case OP_GT:
				case OP_DIV:
				case OP_QUESTION:
				case OP_COLON:
				case LITERAL_position:
				case OP_OR:
				case OP_AND:
				case OP_BITOR:
				case OP_BITAND:
				case OP_EQUALEQUAL:
				case OP_NE:
				case OP_LT:
				case OP_LE:
				case OP_GE:
				case OP_PLUS:
				case OP_MINUS:
				case OP_MULT:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				lookupExpr_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 781 "GrpParser.g"
				lookupExpr_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(astFactory->create(Zlookup))->add(I4_AST)->add(C4_AST)));
#line 8361 "GrpParser.cpp"
				currentAST.root = lookupExpr_AST;
				if ( lookupExpr_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
					lookupExpr_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
					  currentAST.child = lookupExpr_AST->getFirstChild();
				else
					currentAST.child = lookupExpr_AST;
				currentAST.advanceChildToEnd();
			}
			else if ((LA(1) == IDENT || LA(1) == LITERAL_glyph || LA(1) == LITERAL_position) && (_tokenSet_88.member(LA(2))) && (_tokenSet_4.member(LA(3)))) {
				identDot();
				I2_AST = returnAST;
				{
				switch ( LA(1)) {
				case OP_DOT:
				{
					clusterExpr();
					C2_AST = returnAST;
					break;
				}
				case ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE:
				case OP_EQ:
				case OP_RPAREN:
				case OP_SEMI:
				case LITERAL_environment:
				case LITERAL_endenvironment:
				case OP_RBRACE:
				case IDENT:
				case LITERAL_table:
				case LITERAL_endtable:
				case OP_COMMA:
				case LITERAL_glyph:
				case OP_GT:
				case OP_DIV:
				case OP_QUESTION:
				case OP_COLON:
				case LITERAL_position:
				case OP_OR:
				case OP_AND:
				case OP_BITOR:
				case OP_BITAND:
				case OP_EQUALEQUAL:
				case OP_NE:
				case OP_LT:
				case OP_LE:
				case OP_GE:
				case OP_PLUS:
				case OP_MINUS:
				case OP_MULT:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				lookupExpr_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 783 "GrpParser.g"
				lookupExpr_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(astFactory->create(Zlookup))->add(I2_AST)->add(C2_AST)));
#line 8422 "GrpParser.cpp"
				currentAST.root = lookupExpr_AST;
				if ( lookupExpr_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
					lookupExpr_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
					  currentAST.child = lookupExpr_AST->getFirstChild();
				else
					currentAST.child = lookupExpr_AST;
				currentAST.advanceChildToEnd();
			}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_87);
	}
	returnAST = lookupExpr_AST;
}

void GrpParser::selectorExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST selectorExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp287_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp287_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp287_AST);
		match(OP_AT);
		{
		switch ( LA(1)) {
		case LIT_INT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp288_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp288_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp288_AST);
			match(LIT_INT);
			break;
		}
		case Qalias:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp289_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp289_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp289_AST);
			match(Qalias);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		selectorExpr_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_88);
	}
	returnAST = selectorExpr_AST;
}

void GrpParser::glyphIdentDot() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST glyphIdentDot_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp290_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp290_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp290_AST);
		match(LITERAL_glyph);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp291_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp291_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp291_AST);
		match(OP_DOT);
		identDot();
		astFactory->addASTChild( currentAST, returnAST );
		glyphIdentDot_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_88);
	}
	returnAST = glyphIdentDot_AST;
}

void GrpParser::clusterExpr() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST clusterExpr_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefToken  C = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefAST C_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp292_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp292_AST = astFactory->create(LT(1));
		match(OP_DOT);
		C = LT(1);
		C_AST = astFactory->create(C);
		match(LIT_INT);
		clusterExpr_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 790 "GrpParser.g"
		clusterExpr_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(Zcluster))->add(C_AST)));
#line 8529 "GrpParser.cpp"
		currentAST.root = clusterExpr_AST;
		if ( clusterExpr_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			clusterExpr_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = clusterExpr_AST->getFirstChild();
		else
			currentAST.child = clusterExpr_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_87);
	}
	returnAST = clusterExpr_AST;
}

void GrpParser::justifyIdentDot() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST justifyIdentDot_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp293_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp293_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp293_AST);
		match(LITERAL_justify);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp294_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp294_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp294_AST);
		match(OP_DOT);
		justifyIdentDotAux();
		astFactory->addASTChild( currentAST, returnAST );
		justifyIdentDot_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_87);
	}
	returnAST = justifyIdentDot_AST;
}

void GrpParser::justifyIdentDotAux() {
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST justifyIdentDotAux_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		if ((LA(1) == IDENT || LA(1) == LIT_INT) && (LA(2) == OP_DOT)) {
			{
			switch ( LA(1)) {
			case IDENT:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp295_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp295_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp295_AST);
				match(IDENT);
				break;
			}
			case LIT_INT:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp296_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp296_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp296_AST);
				match(LIT_INT);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp297_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp297_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp297_AST);
			match(OP_DOT);
			identDot();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else if ((LA(1) == IDENT || LA(1) == LIT_INT) && (_tokenSet_87.member(LA(2)))) {
			{
			switch ( LA(1)) {
			case IDENT:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp298_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp298_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp298_AST);
				match(IDENT);
				break;
			}
			case LIT_INT:
			{
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp299_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
				tmp299_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, tmp299_AST);
				match(LIT_INT);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		justifyIdentDotAux_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_87);
	}
	returnAST = justifyIdentDotAux_AST;
}

void GrpParser::initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& factory )
{
	factory.setMaxNodeType(113);
}
const char* GrpParser::tokenNames[] = {
	"<0>",
	"EOF",
	"<2>",
	"NULL_TREE_LOOKAHEAD",
	"OP_EQ",
	"OP_PLUSEQUAL",
	"OP_LPAREN",
	"OP_RPAREN",
	"OP_SEMI",
	"\"environment\"",
	"\"endenvironment\"",
	"OP_LBRACE",
	"OP_RBRACE",
	"IDENT",
	"\"table\"",
	"\"endtable\"",
	"\"name\"",
	"LIT_INT",
	"OP_DOT",
	"OP_PLUS_EQUAL",
	"LIT_STRING",
	"OP_COMMA",
	"\"string\"",
	"\"glyph\"",
	"OP_ANDEQUAL",
	"OP_MINUSEQUAL",
	"\"pseudo\"",
	"LIT_UHEX",
	"\"codepoint\"",
	"\"glyphid\"",
	"\"postscript\"",
	"\"unicode\"",
	"OP_DOTDOT",
	"LIT_CHAR",
	"\"feature\"",
	"\"language\"",
	"\"languages\"",
	"\"substitution\"",
	"\"pass\"",
	"\"endpass\"",
	"\"if\"",
	"\"else\"",
	"\"endif\"",
	"Zelseif",
	"\"elseif\"",
	"OP_GT",
	"OP_DIV",
	"OP_QUESTION",
	"OP_LBRACKET",
	"OP_RBRACKET",
	"OP_UNDER",
	"OP_AT",
	"OP_COLON",
	"OP_HASH",
	"OP_DOLLAR",
	"Qalias",
	"\"justification\"",
	"\"position\"",
	"\"positioning\"",
	"\"linebreak\"",
	"OP_CARET",
	"\"justify\"",
	"\"min\"",
	"\"max\"",
	"OP_DIVEQUAL",
	"OP_MULTEQUAL",
	"OP_OR",
	"OP_AND",
	"OP_BITOR",
	"OP_BITAND",
	"OP_EQUALEQUAL",
	"OP_NE",
	"OP_LT",
	"OP_LE",
	"OP_GE",
	"OP_PLUS",
	"OP_MINUS",
	"OP_MULT",
	"OP_NOT",
	"OP_BITNOT",
	"\"true\"",
	"\"false\"",
	"Zalias",
	"Zassocs",
	"Zattrs",
	"Zcluster",
	"Zcodepage",
	"Zconstraint",
	"Zcontext",
	"Zdirectives",
	"ZdotStruct",
	"Zfeatures",
	"Zfunction",
	"ZifStruct",
	"Zlhs",
	"Zlookup",
	"Zrhs",
	"Zrule",
	"ZruleItem",
	"Zselector",
	"Ztop",
	"ZuHex",
	"WS",
	"COMMENT_SL",
	"COMMENT_ML",
	"ESC",
	"ODIGIT",
	"DIGIT",
	"XDIGIT",
	"SQUOTE",
	"DQUOTE",
	"OP_LINEMARKER",
	"OP_BSLASH",
	"AT_IDENT",
	0
};

const unsigned long GrpParser::_tokenSet_0_data_[] = { 2UL, 0UL, 0UL, 0UL };
// EOF 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_0(_tokenSet_0_data_,4);
const unsigned long GrpParser::_tokenSet_1_data_[] = { 9576512UL, 3792175104UL, 251904UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// OP_LPAREN IDENT LIT_INT LIT_STRING "glyph" OP_AT "position" "justify" 
// "min" "max" OP_PLUS OP_MINUS OP_NOT OP_BITNOT "true" "false" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_1(_tokenSet_1_data_,8);
const unsigned long GrpParser::_tokenSet_2_data_[] = { 11935952UL, 3800621056UL, 262140UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_RPAREN IDENT LIT_INT OP_DOT LIT_STRING OP_COMMA "glyph" 
// OP_GT OP_DIV OP_QUESTION OP_AT Qalias "position" "justify" "min" "max" 
// OP_OR OP_AND OP_BITOR OP_BITAND OP_EQUALEQUAL OP_NE OP_LT OP_LE OP_GE 
// OP_PLUS OP_MINUS OP_MULT OP_NOT OP_BITNOT "true" "false" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_2(_tokenSet_2_data_,8);
const unsigned long GrpParser::_tokenSet_3_data_[] = { 9856850UL, 3800621056UL, 262140UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_EQ OP_LPAREN OP_SEMI "environment" "endenvironment" IDENT "table" 
// LIT_INT OP_DOT LIT_STRING "glyph" OP_GT OP_DIV OP_QUESTION OP_AT Qalias 
// "position" "justify" "min" "max" OP_OR OP_AND OP_BITOR OP_BITAND OP_EQUALEQUAL 
// OP_NE OP_LT OP_LE OP_GE OP_PLUS OP_MINUS OP_MULT OP_NOT OP_BITNOT "true" 
// "false" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_3(_tokenSet_3_data_,8);
const unsigned long GrpParser::_tokenSet_4_data_[] = { 4294967282UL, 4294967295UL, 4294967295UL, 262143UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_EQ OP_PLUSEQUAL OP_LPAREN OP_RPAREN OP_SEMI "environment" "endenvironment" 
// OP_LBRACE OP_RBRACE IDENT "table" "endtable" "name" LIT_INT OP_DOT OP_PLUS_EQUAL 
// LIT_STRING OP_COMMA "string" "glyph" OP_ANDEQUAL OP_MINUSEQUAL "pseudo" 
// LIT_UHEX "codepoint" "glyphid" "postscript" "unicode" OP_DOTDOT LIT_CHAR 
// "feature" "language" "languages" "substitution" "pass" "endpass" "if" 
// "else" "endif" Zelseif "elseif" OP_GT OP_DIV OP_QUESTION OP_LBRACKET 
// OP_RBRACKET OP_UNDER OP_AT OP_COLON OP_HASH OP_DOLLAR Qalias "justification" 
// "position" "positioning" "linebreak" OP_CARET "justify" "min" "max" 
// OP_DIVEQUAL OP_MULTEQUAL OP_OR OP_AND OP_BITOR OP_BITAND OP_EQUALEQUAL 
// OP_NE OP_LT OP_LE OP_GE OP_PLUS OP_MINUS OP_MULT OP_NOT OP_BITNOT "true" 
// "false" Zalias Zassocs Zattrs Zcluster Zcodepage Zconstraint Zcontext 
// Zdirectives ZdotStruct Zfeatures Zfunction ZifStruct Zlhs Zlookup Zrhs 
// Zrule ZruleItem Zselector Ztop ZuHex WS COMMENT_SL COMMENT_ML ESC ODIGIT 
// DIGIT XDIGIT SQUOTE DQUOTE OP_LINEMARKER OP_BSLASH AT_IDENT 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_4(_tokenSet_4_data_,8);
const unsigned long GrpParser::_tokenSet_5_data_[] = { 8414722UL, 33554432UL, 0UL, 0UL };
// EOF "environment" "endenvironment" IDENT "table" "glyph" "position" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_5(_tokenSet_5_data_,4);
const unsigned long GrpParser::_tokenSet_6_data_[] = { 10811314UL, 34660352UL, 16380UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_EQ OP_PLUSEQUAL OP_RPAREN OP_SEMI "environment" "endenvironment" 
// OP_RBRACE IDENT "table" "endtable" OP_DOT OP_COMMA "glyph" OP_GT OP_DIV 
// OP_QUESTION OP_COLON "position" OP_OR OP_AND OP_BITOR OP_BITAND OP_EQUALEQUAL 
// OP_NE OP_LT OP_LE OP_GE OP_PLUS OP_MINUS OP_MULT 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_6(_tokenSet_6_data_,8);
const unsigned long GrpParser::_tokenSet_7_data_[] = { 128UL, 0UL, 0UL, 0UL };
// OP_RPAREN 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_7(_tokenSet_7_data_,4);
const unsigned long GrpParser::_tokenSet_8_data_[] = { 10549122UL, 34603008UL, 0UL, 0UL };
// EOF OP_RPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE IDENT 
// "table" "endtable" OP_COMMA "glyph" OP_COLON "position" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_8(_tokenSet_8_data_,4);
const unsigned long GrpParser::_tokenSet_9_data_[] = { 4294967280UL, 4294967295UL, 4294967295UL, 262143UL, 0UL, 0UL, 0UL, 0UL };
// OP_EQ OP_PLUSEQUAL OP_LPAREN OP_RPAREN OP_SEMI "environment" "endenvironment" 
// OP_LBRACE OP_RBRACE IDENT "table" "endtable" "name" LIT_INT OP_DOT OP_PLUS_EQUAL 
// LIT_STRING OP_COMMA "string" "glyph" OP_ANDEQUAL OP_MINUSEQUAL "pseudo" 
// LIT_UHEX "codepoint" "glyphid" "postscript" "unicode" OP_DOTDOT LIT_CHAR 
// "feature" "language" "languages" "substitution" "pass" "endpass" "if" 
// "else" "endif" Zelseif "elseif" OP_GT OP_DIV OP_QUESTION OP_LBRACKET 
// OP_RBRACKET OP_UNDER OP_AT OP_COLON OP_HASH OP_DOLLAR Qalias "justification" 
// "position" "positioning" "linebreak" OP_CARET "justify" "min" "max" 
// OP_DIVEQUAL OP_MULTEQUAL OP_OR OP_AND OP_BITOR OP_BITAND OP_EQUALEQUAL 
// OP_NE OP_LT OP_LE OP_GE OP_PLUS OP_MINUS OP_MULT OP_NOT OP_BITNOT "true" 
// "false" Zalias Zassocs Zattrs Zcluster Zcodepage Zconstraint Zcontext 
// Zdirectives ZdotStruct Zfeatures Zfunction ZifStruct Zlhs Zlookup Zrhs 
// Zrule ZruleItem Zselector Ztop ZuHex WS COMMENT_SL COMMENT_ML ESC ODIGIT 
// DIGIT XDIGIT SQUOTE DQUOTE OP_LINEMARKER OP_BSLASH AT_IDENT 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_9(_tokenSet_9_data_,8);
const unsigned long GrpParser::_tokenSet_10_data_[] = { 4352UL, 0UL, 0UL, 0UL };
// OP_SEMI OP_RBRACE 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_10(_tokenSet_10_data_,4);
const unsigned long GrpParser::_tokenSet_11_data_[] = { 32768UL, 0UL, 0UL, 0UL };
// "endtable" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_11(_tokenSet_11_data_,4);
const unsigned long GrpParser::_tokenSet_12_data_[] = { 4227883584UL, 2949440UL, 0UL, 0UL };
// OP_LPAREN "environment" IDENT "table" "pseudo" LIT_UHEX "codepoint" 
// "glyphid" "postscript" "unicode" "pass" "if" OP_LBRACKET OP_UNDER OP_AT 
// OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_12(_tokenSet_12_data_,4);
const unsigned long GrpParser::_tokenSet_13_data_[] = { 4294934512UL, 4294967295UL, 4294967295UL, 262143UL, 0UL, 0UL, 0UL, 0UL };
// OP_EQ OP_PLUSEQUAL OP_LPAREN OP_RPAREN OP_SEMI "environment" "endenvironment" 
// OP_LBRACE OP_RBRACE IDENT "table" "name" LIT_INT OP_DOT OP_PLUS_EQUAL 
// LIT_STRING OP_COMMA "string" "glyph" OP_ANDEQUAL OP_MINUSEQUAL "pseudo" 
// LIT_UHEX "codepoint" "glyphid" "postscript" "unicode" OP_DOTDOT LIT_CHAR 
// "feature" "language" "languages" "substitution" "pass" "endpass" "if" 
// "else" "endif" Zelseif "elseif" OP_GT OP_DIV OP_QUESTION OP_LBRACKET 
// OP_RBRACKET OP_UNDER OP_AT OP_COLON OP_HASH OP_DOLLAR Qalias "justification" 
// "position" "positioning" "linebreak" OP_CARET "justify" "min" "max" 
// OP_DIVEQUAL OP_MULTEQUAL OP_OR OP_AND OP_BITOR OP_BITAND OP_EQUALEQUAL 
// OP_NE OP_LT OP_LE OP_GE OP_PLUS OP_MINUS OP_MULT OP_NOT OP_BITNOT "true" 
// "false" Zalias Zassocs Zattrs Zcluster Zcodepage Zconstraint Zcontext 
// Zdirectives ZdotStruct Zfeatures Zfunction ZifStruct Zlhs Zlookup Zrhs 
// Zrule ZruleItem Zselector Ztop ZuHex WS COMMENT_SL COMMENT_ML ESC ODIGIT 
// DIGIT XDIGIT SQUOTE DQUOTE OP_LINEMARKER OP_BSLASH AT_IDENT 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_13(_tokenSet_13_data_,8);
const unsigned long GrpParser::_tokenSet_14_data_[] = { 189952UL, 0UL, 0UL, 0UL };
// "environment" "endenvironment" IDENT "table" "endtable" LIT_INT 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_14(_tokenSet_14_data_,4);
const unsigned long GrpParser::_tokenSet_15_data_[] = { 788496UL, 0UL, 0UL, 0UL };
// OP_EQ OP_LBRACE OP_DOT OP_PLUS_EQUAL 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_15(_tokenSet_15_data_,4);
const unsigned long GrpParser::_tokenSet_16_data_[] = { 5386304UL, 0UL, 202752UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// OP_LPAREN OP_RBRACE IDENT LIT_INT LIT_STRING "string" OP_PLUS OP_MINUS 
// "true" "false" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_16(_tokenSet_16_data_,8);
const unsigned long GrpParser::_tokenSet_17_data_[] = { 194304UL, 0UL, 0UL, 0UL };
// OP_SEMI "environment" "endenvironment" OP_RBRACE IDENT "table" "endtable" 
// LIT_INT 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_17(_tokenSet_17_data_,4);
const unsigned long GrpParser::_tokenSet_18_data_[] = { 10745746UL, 34660376UL, 16380UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_EQ OP_RPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE 
// IDENT "table" "endtable" "name" LIT_INT OP_COMMA "glyph" "language" 
// "languages" OP_GT OP_DIV OP_QUESTION OP_COLON "position" OP_OR OP_AND 
// OP_BITOR OP_BITAND OP_EQUALEQUAL OP_NE OP_LT OP_LE OP_GE OP_PLUS OP_MINUS 
// OP_MULT 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_18(_tokenSet_18_data_,8);
const unsigned long GrpParser::_tokenSet_19_data_[] = { 7340096UL, 0UL, 0UL, 0UL };
// OP_LPAREN LIT_STRING OP_COMMA "string" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_19(_tokenSet_19_data_,4);
const unsigned long GrpParser::_tokenSet_20_data_[] = { 7600064UL, 0UL, 0UL, 0UL };
// OP_LPAREN OP_RPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE 
// IDENT "table" "endtable" "name" LIT_INT LIT_STRING OP_COMMA "string" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_20(_tokenSet_20_data_,4);
const unsigned long GrpParser::_tokenSet_21_data_[] = { 58880UL, 0UL, 0UL, 0UL };
// "environment" "endenvironment" IDENT "table" "endtable" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_21(_tokenSet_21_data_,4);
const unsigned long GrpParser::_tokenSet_22_data_[] = { 50331696UL, 0UL, 0UL, 0UL };
// OP_EQ OP_PLUSEQUAL OP_ANDEQUAL OP_MINUSEQUAL 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_22(_tokenSet_22_data_,4);
const unsigned long GrpParser::_tokenSet_23_data_[] = { 61184UL, 0UL, 0UL, 0UL };
// OP_SEMI "environment" "endenvironment" OP_LBRACE IDENT "table" "endtable" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_23(_tokenSet_23_data_,4);
const unsigned long GrpParser::_tokenSet_24_data_[] = { 59136UL, 0UL, 0UL, 0UL };
// OP_SEMI "environment" "endenvironment" IDENT "table" "endtable" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_24(_tokenSet_24_data_,4);
const unsigned long GrpParser::_tokenSet_25_data_[] = { 8527872UL, 3758096384UL, 0UL, 0UL };
// IDENT LIT_INT "glyph" "justify" "min" "max" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_25(_tokenSet_25_data_,4);
const unsigned long GrpParser::_tokenSet_26_data_[] = { 33816624UL, 0UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// OP_EQ OP_PLUSEQUAL OP_DOT OP_MINUSEQUAL OP_DIVEQUAL OP_MULTEQUAL 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_26(_tokenSet_26_data_,8);
const unsigned long GrpParser::_tokenSet_27_data_[] = { 4229963840UL, 0UL, 0UL, 0UL };
// OP_LPAREN IDENT OP_COMMA "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" 
// "unicode" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_27(_tokenSet_27_data_,4);
const unsigned long GrpParser::_tokenSet_28_data_[] = { 4230016976UL, 276815872UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_RPAREN OP_SEMI "environment" "endenvironment" OP_LBRACE 
// IDENT "table" "endtable" OP_COMMA "pseudo" LIT_UHEX "codepoint" "glyphid" 
// "postscript" "unicode" OP_GT OP_DIV OP_QUESTION OP_LBRACKET OP_RBRACKET 
// OP_UNDER OP_AT OP_COLON OP_HASH OP_DOLLAR OP_CARET 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_28(_tokenSet_28_data_,4);
const unsigned long GrpParser::_tokenSet_29_data_[] = { 4227917632UL, 3137536UL, 0UL, 0UL };
// OP_LPAREN OP_SEMI "environment" "endenvironment" IDENT "table" "endtable" 
// "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" "unicode" OP_GT 
// OP_DIV OP_QUESTION OP_LBRACKET OP_RBRACKET OP_UNDER OP_AT OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_29(_tokenSet_29_data_,4);
const unsigned long GrpParser::_tokenSet_30_data_[] = { 33818672UL, 0UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// OP_EQ OP_PLUSEQUAL OP_LBRACE OP_DOT OP_MINUSEQUAL OP_DIVEQUAL OP_MULTEQUAL 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_30(_tokenSet_30_data_,8);
const unsigned long GrpParser::_tokenSet_31_data_[] = { 4227921728UL, 3137536UL, 0UL, 0UL };
// OP_LPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE IDENT "table" 
// "endtable" "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" "unicode" 
// OP_GT OP_DIV OP_QUESTION OP_LBRACKET OP_RBRACKET OP_UNDER OP_AT OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_31(_tokenSet_31_data_,4);
const unsigned long GrpParser::_tokenSet_32_data_[] = { 9576640UL, 3792175104UL, 251904UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// OP_LPAREN OP_RPAREN IDENT LIT_INT LIT_STRING "glyph" OP_AT "position" 
// "justify" "min" "max" OP_PLUS OP_MINUS OP_NOT OP_BITNOT "true" "false" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_32(_tokenSet_32_data_,8);
const unsigned long GrpParser::_tokenSet_33_data_[] = { 9893712UL, 3800621056UL, 262140UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE IDENT 
// "table" "endtable" LIT_INT OP_DOT LIT_STRING "glyph" OP_GT OP_DIV OP_QUESTION 
// OP_AT Qalias "position" "justify" "min" "max" OP_OR OP_AND OP_BITOR 
// OP_BITAND OP_EQUALEQUAL OP_NE OP_LT OP_LE OP_GE OP_PLUS OP_MINUS OP_MULT 
// OP_NOT OP_BITNOT "true" "false" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_33(_tokenSet_33_data_,8);
const unsigned long GrpParser::_tokenSet_34_data_[] = { 63232UL, 0UL, 0UL, 0UL };
// OP_SEMI "environment" "endenvironment" OP_RBRACE IDENT "table" "endtable" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_34(_tokenSet_34_data_,4);
const unsigned long GrpParser::_tokenSet_35_data_[] = { 4230148048UL, 276815872UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_RPAREN OP_SEMI "environment" "endenvironment" OP_LBRACE 
// IDENT "table" "endtable" LIT_INT OP_COMMA "pseudo" LIT_UHEX "codepoint" 
// "glyphid" "postscript" "unicode" OP_GT OP_DIV OP_QUESTION OP_LBRACKET 
// OP_RBRACKET OP_UNDER OP_AT OP_COLON OP_HASH OP_DOLLAR OP_CARET 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_35(_tokenSet_35_data_,4);
const unsigned long GrpParser::_tokenSet_36_data_[] = { 3276800UL, 2UL, 0UL, 0UL };
// LIT_INT LIT_STRING OP_COMMA LIT_CHAR 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_36(_tokenSet_36_data_,4);
const unsigned long GrpParser::_tokenSet_37_data_[] = { 2097280UL, 0UL, 0UL, 0UL };
// OP_RPAREN OP_COMMA 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_37(_tokenSet_37_data_,4);
const unsigned long GrpParser::_tokenSet_38_data_[] = { 3276928UL, 2UL, 0UL, 0UL };
// OP_RPAREN LIT_INT LIT_STRING OP_COMMA LIT_CHAR 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_38(_tokenSet_38_data_,4);
const unsigned long GrpParser::_tokenSet_39_data_[] = { 2228352UL, 0UL, 0UL, 0UL };
// OP_RPAREN LIT_INT OP_COMMA 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_39(_tokenSet_39_data_,4);
const unsigned long GrpParser::_tokenSet_40_data_[] = { 255488UL, 0UL, 0UL, 0UL };
// "environment" "endenvironment" IDENT "table" "endtable" "name" LIT_INT 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_40(_tokenSet_40_data_,4);
const unsigned long GrpParser::_tokenSet_41_data_[] = { 5451840UL, 0UL, 202752UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// OP_LPAREN OP_RBRACE IDENT "name" LIT_INT LIT_STRING "string" OP_PLUS 
// OP_MINUS "true" "false" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_41(_tokenSet_41_data_,8);
const unsigned long GrpParser::_tokenSet_42_data_[] = { 259840UL, 0UL, 0UL, 0UL };
// OP_SEMI "environment" "endenvironment" OP_RBRACE IDENT "table" "endtable" 
// "name" LIT_INT 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_42(_tokenSet_42_data_,4);
const unsigned long GrpParser::_tokenSet_43_data_[] = { 12288UL, 24UL, 0UL, 0UL };
// OP_RBRACE IDENT "language" "languages" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_43(_tokenSet_43_data_,4);
const unsigned long GrpParser::_tokenSet_44_data_[] = { 63232UL, 24UL, 0UL, 0UL };
// OP_SEMI "environment" "endenvironment" OP_RBRACE IDENT "table" "endtable" 
// "language" "languages" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_44(_tokenSet_44_data_,4);
const unsigned long GrpParser::_tokenSet_45_data_[] = { 4096UL, 0UL, 0UL, 0UL };
// OP_RBRACE 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_45(_tokenSet_45_data_,4);
const unsigned long GrpParser::_tokenSet_46_data_[] = { 4227917376UL, 2957248UL, 0UL, 0UL };
// OP_LPAREN "environment" "endenvironment" IDENT "table" "endtable" "pseudo" 
// LIT_UHEX "codepoint" "glyphid" "postscript" "unicode" "pass" "endpass" 
// "if" "else" "endif" Zelseif "elseif" OP_LBRACKET OP_UNDER OP_AT OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_46(_tokenSet_46_data_,4);
const unsigned long GrpParser::_tokenSet_47_data_[] = { 4227917632UL, 2957248UL, 0UL, 0UL };
// OP_LPAREN OP_SEMI "environment" "endenvironment" IDENT "table" "endtable" 
// "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" "unicode" "pass" 
// "endpass" "if" "else" "endif" Zelseif "elseif" OP_LBRACKET OP_UNDER 
// OP_AT OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_47(_tokenSet_47_data_,4);
const unsigned long GrpParser::_tokenSet_48_data_[] = { 0UL, 7680UL, 0UL, 0UL };
// "else" "endif" Zelseif "elseif" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_48(_tokenSet_48_data_,4);
const unsigned long GrpParser::_tokenSet_49_data_[] = { 0UL, 1536UL, 0UL, 0UL };
// "else" "endif" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_49(_tokenSet_49_data_,4);
const unsigned long GrpParser::_tokenSet_50_data_[] = { 4227866688UL, 2949120UL, 0UL, 0UL };
// OP_LPAREN IDENT "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" 
// "unicode" OP_LBRACKET OP_UNDER OP_AT OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_50(_tokenSet_50_data_,4);
const unsigned long GrpParser::_tokenSet_51_data_[] = { 4228000208UL, 16769025UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_RPAREN OP_SEMI OP_LBRACE IDENT LIT_INT "pseudo" LIT_UHEX 
// "codepoint" "glyphid" "postscript" "unicode" OP_DOTDOT OP_GT OP_DIV 
// OP_QUESTION OP_LBRACKET OP_RBRACKET OP_UNDER OP_AT OP_COLON OP_HASH 
// OP_DOLLAR Qalias 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_51(_tokenSet_51_data_,4);
const unsigned long GrpParser::_tokenSet_52_data_[] = { 4239589328UL, 4043308995UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_RPAREN OP_SEMI "environment" "endenvironment" OP_LBRACE 
// OP_RBRACE IDENT "table" "endtable" LIT_INT LIT_STRING OP_COMMA "glyph" 
// "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" "unicode" OP_DOTDOT 
// LIT_CHAR "pass" "endpass" "if" "else" "endif" Zelseif "elseif" OP_GT 
// OP_DIV OP_QUESTION OP_LBRACKET OP_RBRACKET OP_UNDER OP_AT OP_COLON OP_HASH 
// OP_DOLLAR Qalias OP_CARET "justify" "min" "max" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_52(_tokenSet_52_data_,4);
const unsigned long GrpParser::_tokenSet_53_data_[] = { 4227866944UL, 3104768UL, 0UL, 0UL };
// OP_LPAREN OP_SEMI IDENT "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" 
// "unicode" OP_GT OP_DIV OP_LBRACKET OP_RBRACKET OP_UNDER OP_AT OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_53(_tokenSet_53_data_,4);
const unsigned long GrpParser::_tokenSet_54_data_[] = { 4227866688UL, 2883584UL, 0UL, 0UL };
// OP_LPAREN IDENT "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" 
// "unicode" OP_UNDER OP_AT OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_54(_tokenSet_54_data_,4);
const unsigned long GrpParser::_tokenSet_55_data_[] = { 256UL, 16384UL, 0UL, 0UL };
// OP_SEMI OP_DIV 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_55(_tokenSet_55_data_,4);
const unsigned long GrpParser::_tokenSet_56_data_[] = { 4227866688UL, 270860288UL, 0UL, 0UL };
// OP_LPAREN IDENT "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" 
// "unicode" OP_LBRACKET OP_UNDER OP_HASH OP_CARET 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_56(_tokenSet_56_data_,4);
const unsigned long GrpParser::_tokenSet_57_data_[] = { 256UL, 0UL, 0UL, 0UL };
// OP_SEMI 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_57(_tokenSet_57_data_,4);
const unsigned long GrpParser::_tokenSet_58_data_[] = { 4228050896UL, 285212609UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_RPAREN OP_SEMI "environment" "endenvironment" OP_LBRACE 
// IDENT "table" "endtable" LIT_INT "pseudo" LIT_UHEX "codepoint" "glyphid" 
// "postscript" "unicode" OP_DOTDOT "pass" "endpass" "if" "else" "endif" 
// Zelseif "elseif" OP_GT OP_DIV OP_QUESTION OP_LBRACKET OP_RBRACKET OP_UNDER 
// OP_AT OP_COLON OP_HASH OP_DOLLAR Qalias OP_CARET 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_58(_tokenSet_58_data_,4);
const unsigned long GrpParser::_tokenSet_59_data_[] = { 4227866944UL, 3137536UL, 0UL, 0UL };
// OP_LPAREN OP_SEMI IDENT "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" 
// "unicode" OP_GT OP_DIV OP_QUESTION OP_LBRACKET OP_RBRACKET OP_UNDER 
// OP_AT OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_59(_tokenSet_59_data_,4);
const unsigned long GrpParser::_tokenSet_60_data_[] = { 4227869008UL, 4186112UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_SEMI OP_LBRACE IDENT "pseudo" LIT_UHEX "codepoint" 
// "glyphid" "postscript" "unicode" OP_GT OP_DIV OP_QUESTION OP_LBRACKET 
// OP_RBRACKET OP_UNDER OP_AT OP_COLON OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_60(_tokenSet_60_data_,4);
const unsigned long GrpParser::_tokenSet_61_data_[] = { 4228000080UL, 12574720UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_SEMI OP_LBRACE IDENT LIT_INT "pseudo" LIT_UHEX "codepoint" 
// "glyphid" "postscript" "unicode" OP_GT OP_DIV OP_QUESTION OP_LBRACKET 
// OP_RBRACKET OP_UNDER OP_AT OP_COLON OP_HASH Qalias 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_61(_tokenSet_61_data_,4);
const unsigned long GrpParser::_tokenSet_62_data_[] = { 4236443600UL, 4043308993UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_RPAREN OP_SEMI "environment" "endenvironment" OP_LBRACE 
// OP_RBRACE IDENT "table" "endtable" LIT_INT "glyph" "pseudo" LIT_UHEX 
// "codepoint" "glyphid" "postscript" "unicode" OP_DOTDOT "pass" "endpass" 
// "if" "else" "endif" Zelseif "elseif" OP_GT OP_DIV OP_QUESTION OP_LBRACKET 
// OP_RBRACKET OP_UNDER OP_AT OP_COLON OP_HASH OP_DOLLAR Qalias OP_CARET 
// "justify" "min" "max" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_62(_tokenSet_62_data_,4);
const unsigned long GrpParser::_tokenSet_63_data_[] = { 4227868992UL, 3137536UL, 0UL, 0UL };
// OP_LPAREN OP_SEMI OP_LBRACE IDENT "pseudo" LIT_UHEX "codepoint" "glyphid" 
// "postscript" "unicode" OP_GT OP_DIV OP_QUESTION OP_LBRACKET OP_RBRACKET 
// OP_UNDER OP_AT OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_63(_tokenSet_63_data_,4);
const unsigned long GrpParser::_tokenSet_64_data_[] = { 4227869008UL, 7331840UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_SEMI OP_LBRACE IDENT "pseudo" LIT_UHEX "codepoint" 
// "glyphid" "postscript" "unicode" OP_GT OP_DIV OP_QUESTION OP_LBRACKET 
// OP_RBRACKET OP_UNDER OP_AT OP_HASH OP_DOLLAR 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_64(_tokenSet_64_data_,4);
const unsigned long GrpParser::_tokenSet_65_data_[] = { 4227868992UL, 271572992UL, 0UL, 0UL };
// OP_LPAREN OP_SEMI OP_LBRACE IDENT "pseudo" LIT_UHEX "codepoint" "glyphid" 
// "postscript" "unicode" OP_GT OP_DIV OP_QUESTION OP_LBRACKET OP_RBRACKET 
// OP_UNDER OP_AT OP_HASH OP_CARET 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_65(_tokenSet_65_data_,4);
const unsigned long GrpParser::_tokenSet_66_data_[] = { 4230097360UL, 16769024UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_RPAREN OP_SEMI OP_LBRACE IDENT LIT_INT OP_COMMA "pseudo" 
// LIT_UHEX "codepoint" "glyphid" "postscript" "unicode" OP_GT OP_DIV OP_QUESTION 
// OP_LBRACKET OP_RBRACKET OP_UNDER OP_AT OP_COLON OP_HASH OP_DOLLAR Qalias 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_66(_tokenSet_66_data_,4);
const unsigned long GrpParser::_tokenSet_67_data_[] = { 2236416UL, 8388608UL, 0UL, 0UL };
// IDENT LIT_INT OP_COMMA Qalias 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_67(_tokenSet_67_data_,4);
const unsigned long GrpParser::_tokenSet_68_data_[] = { 4227999952UL, 16744449UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_RPAREN OP_LBRACE IDENT LIT_INT "pseudo" LIT_UHEX 
// "codepoint" "glyphid" "postscript" "unicode" OP_DOTDOT OP_QUESTION OP_LBRACKET 
// OP_RBRACKET OP_UNDER OP_AT OP_COLON OP_HASH OP_DOLLAR Qalias 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_68(_tokenSet_68_data_,4);
const unsigned long GrpParser::_tokenSet_69_data_[] = { 4239538640UL, 3774840835UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_RPAREN OP_SEMI OP_LBRACE OP_RBRACE IDENT LIT_INT 
// LIT_STRING OP_COMMA "glyph" "pseudo" LIT_UHEX "codepoint" "glyphid" 
// "postscript" "unicode" OP_DOTDOT LIT_CHAR OP_QUESTION OP_LBRACKET OP_RBRACKET 
// OP_UNDER OP_AT OP_COLON OP_HASH OP_DOLLAR Qalias "justify" "min" "max" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_69(_tokenSet_69_data_,4);
const unsigned long GrpParser::_tokenSet_70_data_[] = { 4227866688UL, 3080192UL, 0UL, 0UL };
// OP_LPAREN IDENT "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" 
// "unicode" OP_LBRACKET OP_RBRACKET OP_UNDER OP_AT OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_70(_tokenSet_70_data_,4);
const unsigned long GrpParser::_tokenSet_71_data_[] = { 4227866688UL, 3112960UL, 0UL, 0UL };
// OP_LPAREN IDENT "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" 
// "unicode" OP_QUESTION OP_LBRACKET OP_RBRACKET OP_UNDER OP_AT OP_HASH 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_71(_tokenSet_71_data_,4);
const unsigned long GrpParser::_tokenSet_72_data_[] = { 4227866944UL, 270991360UL, 0UL, 0UL };
// OP_LPAREN OP_SEMI IDENT "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" 
// "unicode" OP_LBRACKET OP_RBRACKET OP_UNDER OP_HASH OP_CARET 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_72(_tokenSet_72_data_,4);
const unsigned long GrpParser::_tokenSet_73_data_[] = { 4227919824UL, 271556545UL, 0UL, 0UL };
// OP_EQ OP_LPAREN OP_RPAREN OP_SEMI "environment" "endenvironment" OP_LBRACE 
// IDENT "table" "endtable" "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" 
// "unicode" OP_DOTDOT "pass" "endpass" "if" "else" "endif" Zelseif "elseif" 
// OP_QUESTION OP_LBRACKET OP_RBRACKET OP_UNDER OP_AT OP_HASH OP_CARET 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_73(_tokenSet_73_data_,4);
const unsigned long GrpParser::_tokenSet_74_data_[] = { 4227866944UL, 271024128UL, 0UL, 0UL };
// OP_LPAREN OP_SEMI IDENT "pseudo" LIT_UHEX "codepoint" "glyphid" "postscript" 
// "unicode" OP_QUESTION OP_LBRACKET OP_RBRACKET OP_UNDER OP_HASH OP_CARET 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_74(_tokenSet_74_data_,4);
const unsigned long GrpParser::_tokenSet_75_data_[] = { 4294918128UL, 4294967295UL, 4294967295UL, 262143UL, 0UL, 0UL, 0UL, 0UL };
// OP_EQ OP_PLUSEQUAL OP_LPAREN OP_RPAREN OP_SEMI "environment" "endenvironment" 
// OP_LBRACE OP_RBRACE IDENT "name" LIT_INT OP_DOT OP_PLUS_EQUAL LIT_STRING 
// OP_COMMA "string" "glyph" OP_ANDEQUAL OP_MINUSEQUAL "pseudo" LIT_UHEX 
// "codepoint" "glyphid" "postscript" "unicode" OP_DOTDOT LIT_CHAR "feature" 
// "language" "languages" "substitution" "pass" "endpass" "if" "else" "endif" 
// Zelseif "elseif" OP_GT OP_DIV OP_QUESTION OP_LBRACKET OP_RBRACKET OP_UNDER 
// OP_AT OP_COLON OP_HASH OP_DOLLAR Qalias "justification" "position" "positioning" 
// "linebreak" OP_CARET "justify" "min" "max" OP_DIVEQUAL OP_MULTEQUAL 
// OP_OR OP_AND OP_BITOR OP_BITAND OP_EQUALEQUAL OP_NE OP_LT OP_LE OP_GE 
// OP_PLUS OP_MINUS OP_MULT OP_NOT OP_BITNOT "true" "false" Zalias Zassocs 
// Zattrs Zcluster Zcodepage Zconstraint Zcontext Zdirectives ZdotStruct 
// Zfeatures Zfunction ZifStruct Zlhs Zlookup Zrhs Zrule ZruleItem Zselector 
// Ztop ZuHex WS COMMENT_SL COMMENT_ML ESC ODIGIT DIGIT XDIGIT SQUOTE DQUOTE 
// OP_LINEMARKER OP_BSLASH AT_IDENT 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_75(_tokenSet_75_data_,8);
const unsigned long GrpParser::_tokenSet_76_data_[] = { 8417088UL, 33554432UL, 0UL, 0UL };
// OP_LPAREN OP_SEMI "environment" "endenvironment" OP_LBRACE IDENT "table" 
// "glyph" "position" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_76(_tokenSet_76_data_,4);
const unsigned long GrpParser::_tokenSet_77_data_[] = { 10549122UL, 34635776UL, 0UL, 0UL };
// EOF OP_RPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE IDENT 
// "table" "endtable" OP_COMMA "glyph" OP_QUESTION OP_COLON "position" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_77(_tokenSet_77_data_,4);
const unsigned long GrpParser::_tokenSet_78_data_[] = { 10549122UL, 34635776UL, 4UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_RPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE IDENT 
// "table" "endtable" OP_COMMA "glyph" OP_QUESTION OP_COLON "position" 
// OP_OR 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_78(_tokenSet_78_data_,8);
const unsigned long GrpParser::_tokenSet_79_data_[] = { 10549122UL, 34635776UL, 12UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_RPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE IDENT 
// "table" "endtable" OP_COMMA "glyph" OP_QUESTION OP_COLON "position" 
// OP_OR OP_AND 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_79(_tokenSet_79_data_,8);
const unsigned long GrpParser::_tokenSet_80_data_[] = { 10549122UL, 34635776UL, 28UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_RPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE IDENT 
// "table" "endtable" OP_COMMA "glyph" OP_QUESTION OP_COLON "position" 
// OP_OR OP_AND OP_BITOR 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_80(_tokenSet_80_data_,8);
const unsigned long GrpParser::_tokenSet_81_data_[] = { 16UL, 8192UL, 1984UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// OP_EQ OP_GT OP_EQUALEQUAL OP_NE OP_LT OP_LE OP_GE 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_81(_tokenSet_81_data_,8);
const unsigned long GrpParser::_tokenSet_82_data_[] = { 10549122UL, 34635776UL, 60UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_RPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE IDENT 
// "table" "endtable" OP_COMMA "glyph" OP_QUESTION OP_COLON "position" 
// OP_OR OP_AND OP_BITOR OP_BITAND 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_82(_tokenSet_82_data_,8);
const unsigned long GrpParser::_tokenSet_83_data_[] = { 10549138UL, 34643968UL, 2044UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_EQ OP_RPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE 
// IDENT "table" "endtable" OP_COMMA "glyph" OP_GT OP_QUESTION OP_COLON 
// "position" OP_OR OP_AND OP_BITOR OP_BITAND OP_EQUALEQUAL OP_NE OP_LT 
// OP_LE OP_GE 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_83(_tokenSet_83_data_,8);
const unsigned long GrpParser::_tokenSet_84_data_[] = { 10549138UL, 34643968UL, 8188UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_EQ OP_RPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE 
// IDENT "table" "endtable" OP_COMMA "glyph" OP_GT OP_QUESTION OP_COLON 
// "position" OP_OR OP_AND OP_BITOR OP_BITAND OP_EQUALEQUAL OP_NE OP_LT 
// OP_LE OP_GE OP_PLUS OP_MINUS 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_84(_tokenSet_84_data_,8);
const unsigned long GrpParser::_tokenSet_85_data_[] = { 9576512UL, 3792175104UL, 202752UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// OP_LPAREN IDENT LIT_INT LIT_STRING "glyph" OP_AT "position" "justify" 
// "min" "max" OP_PLUS OP_MINUS "true" "false" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_85(_tokenSet_85_data_,8);
const unsigned long GrpParser::_tokenSet_86_data_[] = { 11990994UL, 3801669632UL, 262140UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_EQ OP_LPAREN OP_RPAREN OP_SEMI "environment" "endenvironment" 
// OP_RBRACE IDENT "table" "endtable" LIT_INT OP_DOT LIT_STRING OP_COMMA 
// "glyph" OP_GT OP_DIV OP_QUESTION OP_AT OP_COLON Qalias "position" "justify" 
// "min" "max" OP_OR OP_AND OP_BITOR OP_BITAND OP_EQUALEQUAL OP_NE OP_LT 
// OP_LE OP_GE OP_PLUS OP_MINUS OP_MULT OP_NOT OP_BITNOT "true" "false" 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_86(_tokenSet_86_data_,8);
const unsigned long GrpParser::_tokenSet_87_data_[] = { 10549138UL, 34660352UL, 16380UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_EQ OP_RPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE 
// IDENT "table" "endtable" OP_COMMA "glyph" OP_GT OP_DIV OP_QUESTION OP_COLON 
// "position" OP_OR OP_AND OP_BITOR OP_BITAND OP_EQUALEQUAL OP_NE OP_LT 
// OP_LE OP_GE OP_PLUS OP_MINUS OP_MULT 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_87(_tokenSet_87_data_,8);
const unsigned long GrpParser::_tokenSet_88_data_[] = { 10811282UL, 34660352UL, 16380UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF OP_EQ OP_RPAREN OP_SEMI "environment" "endenvironment" OP_RBRACE 
// IDENT "table" "endtable" OP_DOT OP_COMMA "glyph" OP_GT OP_DIV OP_QUESTION 
// OP_COLON "position" OP_OR OP_AND OP_BITOR OP_BITAND OP_EQUALEQUAL OP_NE 
// OP_LT OP_LE OP_GE OP_PLUS OP_MINUS OP_MULT 
const ANTLR_USE_NAMESPACE(antlr)BitSet GrpParser::_tokenSet_88(_tokenSet_88_data_,8);


