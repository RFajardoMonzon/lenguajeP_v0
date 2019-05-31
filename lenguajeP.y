%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h> 
	#include <limits.h> 

	// stuff from flex that bison needs to know about:
	extern int yylex();
	extern int yyparse();
	extern int numlin;
	extern FILE *yyin;

	void yyerror(const char *s);

	char* removeQuotes(char* s);

	struct symbol{
		int type;
		int memDir;
		int size;
		char* name;
		int* values;
		int scope;
	};

	struct Stack { 
		int top; 
		unsigned capacity; 
		struct symbol* array; 
	};
	
	struct Stack* stack;

	FILE* fp;
	
	int currentScope = 0;
	int memoryDir = 73728;
	int localOffset = 0;
	int nextLabel = 1;
	int nextStatBlock = 1;
	int emptyStringDir;
	int currentReg = 0;
	int currentFloatReg = 0;
	int inFor = 0;
	int initFor, endFor; //pos memoria variables inicio y final del for
	int listPosition;

	void advanceRegister();
	void advanceFloatRegister();
	void reduceScope();

	void initQFile();
	void initTextQ(char* string);
	int getStringLength(char* string);
	void loadAndPrintQ(char* string);
	void printStringQ(int memDir); 
	void printQVariable(char* string); 
	void printQListAccess();
	void loadRegisterOperatorQ(int reg);
	void getNegationQ(int neg);
	void getComparatornQ(int comp);
	void listAccessVar(char* listName, char* accessName);
	void listAccessInt(char* listName, int accessPos);
	void assignTextQ(char* string, int offset);
	int foreachVarQ(char* localVar, char* listName);
	struct symbol initForeachVar(char* localVar);

	int isNotVar(int type);
	int varIsInt(int type);
	int varIsFloat(int type);
	int varIsString(int type);
	int varIsList(int type);

	void resetRegs();
	void doExpr(int r1, int r2, char* op);	
	void initNumVarQ(char* varName, int reg);
	void initTextVarQ(char* varName, int reg);
	void initListPositionQ(int reg);
	int getStringRegQ(char* string);
	int getVarnameRegQ(char* varName);
	void printFromReg(int reg);
	void processCondition(int r1, int r2, char* comp);

	void changeSymbolType(char* varName, int type);
	char* notImplemented();
	char* intToString(int number);
	char* floatToString(float number);
	struct symbol getSymbol(char* varName);
	struct Stack* createStack(unsigned capacity);
	void push(struct Stack* stack, struct symbol item);
	int isEmpty(struct Stack* stack); 
	void pop(struct Stack* stack); 
	void removeScope(struct Stack* stack);

%}

%union {int entero; float real; char* string;}
%token TEXT NUM LIST
%token PLUS MINUS TIMES DIVIDED_BY MOD
%token <entero> INT
%token <real> FLOAT
%token <string> VARNAME STRING
%token IS IF THEN FROM TO DO DONE ENDFUNC
%token SHOW TAB
%token NOT GREATER LOWER GEQUALS LEQUALS EQUALS NOT_EQUALS
%token AND OR
%token FOREACH IN
%token FUNC RETURN
%token OPEN_BRACKET CLOSE_BRACKET OPEN_PAREN CLOSE_PAREN

%type <entero> expr
%type <string> comparator negation

%left SHOW
%left NOT GREATER LOWER GEQUALS LEQUALS EQUALS NOT_EQUALS IS VARNAME INT FLOAT STRING
%left PLUS MINUS
%left TIMES DIVIDED_BY MOD
%left OPEN_PAREN CLOSE_PAREN


%%

lenguajeP:
	lenguajeP line
	|;

line:
	init
	//| access
	| show 
	| ifClause
	//| fromClause
	| initFunction
	//| foreachClause
	| returnClause
	| function;

init:
	initNum
	| initText
	| initList;

initNum:
	NUM VARNAME asignator expr {initNumVarQ($2, $4);};
initText:
	TEXT VARNAME asignator expr {initTextVarQ($2, $4);};

asignator:
	IS
	| '=';

initList:
	LIST NUM VARNAME {struct symbol s; s = getSymbol($3); if (s.type != -1) yyerror("La variable ya ha sido inicializada"); else {$<entero>$ = localOffset; listPosition = 0;}} asignator numList {struct symbol s; s.memDir = $<entero>4; s.type = 3; s.name = $3; s.scope = currentScope; s.size = listPosition; push(stack, s);};
numList:
	expr {initListPositionQ($1);} ',' numList
	| expr {initListPositionQ($1);};

/*access:
	accessNum
	| accessText
	| accessListAccess
	| VARNAME asignator VARNAME;

accessNum:
	VARNAME asignator INT {struct symbol s; s = getSymbol($1); if (s.type == -1) yyerror("la variable no ha sido inicializada."); else if (s.type > 1) yyerror("La variable no es de tipo numérico."); else {changeSymbolType($1, 0); fprintf(fp, "\tI(R7-%i)=%i;\n", s.memDir, $3);}}
	| VARNAME asignator FLOAT {struct symbol s; s = getSymbol($1); if (s.type == -1) yyerror("la variable no ha sido inicializada."); else if (s.type > 1) yyerror("La variable no es de tipo numérico."); else {changeSymbolType($1, 1); fprintf(fp, "\tF(R7-%i)=%f;\n", s.memDir, $3);}}
	| VARNAME asignator expr 
	| VARNAME asignator function;

accessText:
	VARNAME asignator STRING {struct symbol s; s = getSymbol($1); if (s.type == -1) yyerror("la variable no ha sido inicializada."); else if (s.type != 2) yyerror("La variable no es de tipo texto."); else {memoryDir -= getStringLength($3); assignTextQ(removeQuotes($3), s.memDir);}};

accessListAccess:
	listAccess asignator INT
	| listAccess asignator FLOAT;


	
number:
	INT {fprintf(fp, "\tR%i=%i;\n", currentReg, $1); $$ = currentReg; advanceRegister(); }
	| FLOAT {fprintf(fp, "\tRR%i=%f;\n", currentFloatReg, $1); $$ = currentFloatReg + 10; advanceFloatRegister();};*/
expr:
	expr PLUS expr {doExpr($1, $3, "+"); $$ = $1;}
	| expr MINUS expr {doExpr($1, $3, "-"); $$ = $1;}
	| expr TIMES expr {doExpr($1, $3, "*"); $$ = $1;}
	| expr DIVIDED_BY expr {doExpr($1, $3, "/"); $$ = $1;}
	| expr MOD expr {doExpr($1, $3, "%"); $$ = $1;}
	| OPEN_PAREN expr CLOSE_PAREN {$$ = 2;}
	| VARNAME {$$ = getVarnameRegQ($1);} 
	| INT {fprintf(fp, "\tR%i=%i;\n", currentReg, $1); $$ = currentReg; advanceRegister();}
	| FLOAT {fprintf(fp, "\tRR%i=%f;\n", currentReg, $1); $$ = currentReg + 10; advanceFloatRegister();}
	| STRING {$$ = getStringRegQ(removeQuotes($1)); advanceRegister();}
	//| listAccess
	| function {$$ = 2;};

show:
	SHOW expr {printFromReg($2);}
	| SHOW {printStringQ(emptyStringDir);};

ifClause:
	IF expr negation comparator expr THEN {processCondition($2, $5, $4); $<entero>$ = nextLabel++; fprintf(fp, "\n\tIF(%sR0) GT(%i);\n", $3, $<entero>$); resetRegs(); currentScope++;} lenguajeP DONE {fprintf(fp, "L %i:\n", $<entero>4); reduceScope(); resetRegs();};

negation:
	NOT {$$ = "";}
	|{$$ = "!";};
comparator:
	GREATER {$$ = ">";}
	| LOWER {$$ = "<";}
	| IS {$$ = "==";}
	| GEQUALS {$$ = ">=";}
	| LEQUALS {$$ = "<=";}
	| EQUALS {$$ = "==";}
	| NOT_EQUALS {$$ = "!=";}; 

/*fromClause:
	FROM {if (inFor == 1) yyerror("Ya se encuentra en un bucle FROM. Este lenguaje no permite bucles FROM anidados."); else {inFor = 1; currentScope++; fprintf(fp, "\tR5=0;\nL %i:\n", nextLabel); $<entero>$ = nextLabel; nextLabel += 2; struct symbol s; s.name = "iter"; localOffset += 4; s.memDir = localOffset; s.scope = currentScope; push(stack, s);}} fromable TO fromable {fprintf(fp, "\tR0=R0+R5;\n\tI(R7-%i)=R0;\n\tIF(R0>R1) GT(%i);\n", getSymbol("iter").memDir, $<entero>2 + 1);} DO lenguajeP {fprintf(fp, "\tR5=R5+1;\n\tGT(%i);\nL %i:\n", $<entero>2, $<entero>2 + 1);} DONE {inFor = 0; reduceScope();};

fromable:
	VARNAME {struct symbol s = getSymbol($1); if (s.type != 0) yyerror("No se puede iterar sobre un número no entero."); else {fprintf(fp, "\tR%i=I(R7-%i);\n", currentReg, s.memDir); advanceRegister();}}
	| INT {fprintf(fp, "\tR%i=%i;\n", currentReg, $1); advanceRegister();}
	| FLOAT {yyerror("No se puede iterar sobre un número no entero."); exit(1);};

foreachClause:
	FOREACH VARNAME IN VARNAME DO {currentScope++; $<entero>$ = foreachVarQ($<string>2, $<string>4);} lenguajeP {fprintf(fp, "\tR5=R5+1;\n\tGT(%i);\nL %i:\n", $<entero>6, $<entero>6 + 1);} DONE {reduceScope();}
	| FOREACH VARNAME IN {$<entero>$ = localOffset; listPosition = 0;} numList {struct symbol s; s.memDir = $<entero>4; s.type = 3; s.name = "foreach"; s.scope = ++currentScope; s.size = listPosition; push(stack, s);} DO {$<entero>$ = foreachVarQ($<string>2, "foreach");} lenguajeP {fprintf(fp, "\tR5=R5+1;\n\tGT(%i);\nL %i:\n", $<entero>8, $<entero>8 + 1);} DONE {reduceScope();}; 

listAccess:
	VARNAME OPEN_BRACKET VARNAME CLOSE_BRACKET {listAccessVar($<string>1, $<string>3);}
	| VARNAME OPEN_BRACKET INT CLOSE_BRACKET {listAccessInt($<string>1, $<entero>3);};*/

initFunction:
	FUNC function lenguajeP ENDFUNC;
funcParam:
	VARNAME ',' funcParam
	| VARNAME;
function:
	VARNAME OPEN_PAREN funcParam CLOSE_PAREN;

returnClause:
	RETURN expr;
	
%%

int main(int argc, char** argv) {	
	stack = createStack(100);
	fp = fopen("compiled.q.c", "w");
	initQFile();

	if (argc > 1) yyin = fopen(argv[1], "r");
	else yyin = stdin;	
	yyparse();

	fprintf(fp, "\tGT(-2);\nEND"); //Fin del programa, se le añadiría un código de salida a R0
	fclose(fp);

	return 0;
	
}

void advanceRegister(){
	if (currentReg == 4) currentReg = 0;
	else currentReg++;
}

void advanceFloatRegister(){
	if (currentFloatReg == 3) currentFloatReg = 0;
	else currentFloatReg++;
}

int isNotVar(int type){
	return (type == -1);
}

int varIsInt(int type){
	return (type == 0);
}

int varIsFloat(int type){
	return (type == 1);
}

int varIsString(int type){
	return (type == 2);
}

int varIsList(int type){
	return (type == 3);
}

void doExpr(int r1, int r2, char* op){
	fprintf(fp, "\tR%i=R%i%sR%i;\n", r1, r1, op, r2); currentReg--;
}	

void initQFile(){	
	fprintf(fp, "#include \"Q.h\"\n\nBEGIN\nL 0:\nSTAT(0)\n");
	fprintf(fp, "\tSTR(%i, \"\\n\");\n", memoryDir -= 4);
	fprintf(fp, "\tSTR(%i, \"%%i\");\n", memoryDir -= 4);
	fprintf(fp, "\tSTR(%i, \"%%f\");\n", memoryDir -= 4);
	fprintf(fp, "\tSTR(%i, \"\");\n", memoryDir -= 4);
	emptyStringDir = memoryDir;
	fprintf(fp, "CODE(0)\n");
	fprintf(fp, "\tR6=R7;\n");
}

void resetRegs(){
	currentReg = 0;
	currentFloatReg = 0;
}

void initNumVarQ(char* varName, int reg){
	struct symbol s = getSymbol(varName);
	if (!isNotVar(s.type)) yyerror("La variable ya existe.");
	if (reg < -9) yyerror("Una variable numérica no puede inicializarse con una String"); // es string
	if (reg > 9) {
		reg -= 10;
		s.type = 1;
		s.name = varName;
		localOffset += 4;
		s.memDir = localOffset;
		s.scope = currentScope;
		fprintf(fp, "\tF(R6-%i)=RR%i;\n", s.memDir, reg);
		push(stack, s);
		resetRegs();
	} else {
		s.type = 0;
		s.name = varName;
		localOffset += 4;
		s.memDir = localOffset;
		s.scope = currentScope;
		fprintf(fp, "\tI(R6-%i)=R%i;\n", s.memDir, reg);
		push(stack, s);
		resetRegs();
	}
}

int getStringLength(char* string){
	int length = strlen(string);
	if (length == 0) return 4;	
	else if (length % 4 != 0){
		return (length / 4 + 1) * 4;
	}
	return length;
}

void initTextVarQ(char* varName, int reg){
	struct symbol s = getSymbol(varName);
	if (!isNotVar(s.type)) yyerror("La variable ya existe.");
	if (reg >= 0) yyerror("Una variable tipo texto no se puede inicializar con un número.");
	else {
		reg += 10;
		s.type = 2;
		s.name = varName;
		localOffset += 4;
		s.memDir = localOffset;
		s.scope = currentScope;
		fprintf(fp, "\tI(R6-%i)=R%i;\n", s.memDir, reg);
		push(stack, s);
		resetRegs();
	}
}

void initListPositionQ(int reg){
	if (reg < 0) yyerror("La lista solo admite valores numéricos.");
	else {
		localOffset += 4;
		if (reg > 9) fprintf(fp, "\tF(R6-%i)=RR%i;\n", localOffset, reg-10);
		else {
			fprintf(fp, "\tF(R6-%i)=R%i;\n", localOffset, reg);
		}
		
	}
	resetRegs();
}

int getStringRegQ(char* string){
	int length = getStringLength(string);
	fprintf(fp, "STAT(%i)\n", nextStatBlock);
	fprintf(fp, "\tSTR(%i, \"%s\");\n", memoryDir -= length, string);
	fprintf(fp, "CODE(%i)\n", nextStatBlock++);
	fprintf(fp, "\tR%i=%i;\n", currentReg, memoryDir);
	return currentReg-10;
}

int getVarnameRegQ(char* varName){
	struct symbol s = getSymbol(varName);
	if (isNotVar(s.type)) yyerror("La variable no existe.");
	else if (varIsInt(s.type)){
		fprintf(fp, "\tR%i=I(R6-%i);\n", currentReg, s.memDir);
		int reg = currentReg;
		advanceRegister();
		return reg;
	} else if (varIsFloat(s.type)){
		fprintf(fp, "\tRR%i=F(R6-%i);\n", currentFloatReg, s.memDir);
		int reg = currentFloatReg + 10;
		advanceFloatRegister();
		return reg;
	} else if (varIsString(s.type)){
		fprintf(fp, "\tR%i=I(R6-%i);\n", currentReg, s.memDir);
		int reg = currentReg - 10;
		advanceRegister();
		return reg;
	} else {
		yyerror("No se puede realizar esta operación con una lista.");
	}
}

void printFromReg(int reg){
	if (reg < 0){
		fprintf(fp, "\tR1=R%i;\n", reg+10);
		fprintf(fp, "\tR0=%i;\n", nextLabel);
		fprintf(fp, "\tGT(putf_);\n");
		fprintf(fp, "L %i:\n", nextLabel++);
	} else if (reg > 9){
		fprintf(fp, "\tRR1=RR%i;\n", reg-10);
		fprintf(fp, "\tR0=%i;\n", nextLabel);
		fprintf(fp, "\tGT(printfloat_);\n");
		fprintf(fp, "L %i:\n", nextLabel++);
	} else {
		fprintf(fp, "\tR1=R%i;\n", reg);
		fprintf(fp, "\tR0=%i;\n", nextLabel);
		fprintf(fp, "\tGT(printint_);\n");
		fprintf(fp, "L %i:\n", nextLabel++);
	}
}

void processCondition(int r1, int r2, char* comp){
	fprintf(fp, "\tR0=");
	loadRegisterOperatorQ(r1);
	fprintf(fp, "%s", comp);
	loadRegisterOperatorQ(r2);
	fprintf(fp, ";");
}

void loadRegisterOperatorQ(int reg){
	if (reg < 0) yyerror("No se puede comparar una variable texto.");
	else if (reg > 9) fprintf(fp, "RR%i", reg - 10);
	else fprintf(fp, "R%i", reg);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initTextQ(char* string){
	fprintf(fp, "STAT(%i)\n", nextStatBlock);
	fprintf(fp, "\tSTR(%i, \"%s\");\n", memoryDir, string);
	fprintf(fp, "CODE(%i)\n", nextStatBlock++);
	fprintf(fp, "\tI(R7-%i)=%i;\n", localOffset, memoryDir);
}

void assignTextQ(char* string, int offset){
	fprintf(fp, "STAT(%i)\n", nextStatBlock);
	fprintf(fp, "\tSTR(%i, \"%s\");\n", memoryDir, string);
	fprintf(fp, "CODE(%i)\n", nextStatBlock++);
	fprintf(fp, "\tI(R7-%i)=%i;\n", offset, memoryDir);
}

void loadAndPrintQ(char* string){
	int length = getStringLength(string);
	fprintf(fp, "STAT(%i)\n", nextStatBlock);
	fprintf(fp, "\tSTR(%i, \"%s\");\n", memoryDir -= length, string);
	fprintf(fp, "CODE(%i)\n", nextStatBlock++);
	fprintf(fp, "\tR1=%i;\n", memoryDir);
	fprintf(fp, "\tR0=%i;\n", nextLabel);
	fprintf(fp, "\tGT(putf_);\n");
	fprintf(fp, "L %i:\n", nextLabel++);
}

void printStringQ(int memDir){
	fprintf(fp, "\tR1=I(R7-%i);\n", memDir);
	fprintf(fp, "\tR0=%i;\n", nextLabel);
	fprintf(fp, "\tGT(putf_);\n");
	fprintf(fp, "L %i:\n", nextLabel++);
} 

void printQVariable(char* varName){
	struct symbol s = getSymbol(varName);
	if (s.type == -1) yyerror("La variable no existe.");
	else if (s.type == 2) printStringQ(s.memDir);
	else if (s.type == 1) {
		fprintf(fp, "\tRR1=F(R7-%i);\n", s.memDir);
		fprintf(fp, "\tR0=%i;\n", nextLabel);
		fprintf(fp, "\tGT(printfloat_);\n");
		fprintf(fp, "L %i:\n", nextLabel++);
	} else {
		fprintf(fp, "\tR1=I(R7-%i);\n", s.memDir);
		fprintf(fp, "\tR0=%i;\n", nextLabel);
		fprintf(fp, "\tGT(printint_);\n");
		fprintf(fp, "L %i:\n", nextLabel++);
	}
}

void printQListAccess(){
	fprintf(fp, "\tRR1=RR0;\n");
	fprintf(fp, "\tR0=%i;\n", nextLabel);
	fprintf(fp, "\tGT(printfloat_);\n");
	fprintf(fp, "L %i:\n", nextLabel++);
}



void getNegationQ(int neg){
	if (neg == 0) fprintf(fp, "!");
}

void getComparatorQ(int comp){
	char* strComp;
	switch (comp){
		case 0:
			strComp = ">";
			break;
		case 1:
			strComp = "<";
			break;
		case 2:
			strComp = "==";
			break;
		case 3:
			strComp = ">=";
			break;
		case 4:
			strComp = "<=";
			break;
		case 5:
			strComp = "!=";
			break;
		default:
			break;
	}
	fprintf(fp, "%s", strComp);
}



void listAccessVar(char* listName, char* accessName){
	struct symbol l = getSymbol(listName);
	if (l.type != 3) yyerror("La variable no es una lista");
	else {
		struct symbol s = getSymbol(accessName);
		if (s.type != 0) yyerror("Solo se puede acceder a una lista con un entero.");
		else {
			fprintf(fp, "\tR0=%i;\n", l.size);
			fprintf(fp, "\tR1=I(R7-%i);\n", s.memDir);
			fprintf(fp, "\tIF(R1<0) GT(-2);\n");
			fprintf(fp, "\tIF(R1>=R0) GT(-2);\n"); //Se sale del límite del array
			fprintf(fp, "\tR0=4*R1;\n");
			fprintf(fp, "\tR0=R0+4;\n");
			fprintf(fp, "\tR0=%i+R0;\n", l.memDir);
			fprintf(fp, "\tRR0=F(R7-R0);\n");
		}
	}
}

void listAccessInt(char* listName, int accessValue){
	struct symbol l = getSymbol(listName);
	if (l.type != 3) yyerror("La variable no es una lista");
	else {
		fprintf(fp, "\tR0=%i;\n", l.size);
		fprintf(fp, "\tR1=%i;\n", accessValue);
		fprintf(fp, "\tIF(R1<0) GT(-2);\n");
		fprintf(fp, "\tIF(R1>=R0) GT(-2);\n"); //Se sale del límite del array
		fprintf(fp, "\tR0=4*R1;\n");
		fprintf(fp, "\tR0=R0+4;\n");
		fprintf(fp, "\tR0=%i+R0;\n", l.memDir);
		fprintf(fp, "\tRR0=F(R7-R0);\n");		
	}
}

struct symbol initForeachVar(char* localVar){	
	struct symbol s;
	s.name = localVar;
	localOffset += 4;
	s.memDir = localOffset;
	s.type = 1;
	s.scope = currentScope;
	push(stack, s);
	return s;
}

int foreachVarQ(char* localVar, char* listName){ //////////////////////////////////////////////////////////////////////////////////////////////
	struct symbol l = getSymbol(listName);
	if (l.type != 3) yyerror("La variable no es una lista");	
	struct symbol s = initForeachVar(localVar);
	fprintf(fp, "\tR5=1;\nL %i:\n", nextLabel); 
	int endLabel = nextLabel;
	nextLabel += 2;
	fprintf(fp, "\tR1=%i;\n\tIF(R5>R1) GT(%i);\n", l.size, endLabel + 1);
	fprintf(fp, "\tR0=4*R5;\n");
	fprintf(fp, "\tR0=%i+R0;\n", l.memDir);
	fprintf(fp, "\tR0=I(R7-R0);\n\tI(R7-%i)=R0;\n", s.memDir);
	return endLabel;
}

char* removeQuotes(char* s){
	char* res = s; 	
	res++;
	res[strlen(res)-1] = 0;
	return res;
}

void changeSymbolType(char* varName, int type){
	int i;
	for (i = 0; i <= stack->top; i++){
		if (strcmp(varName, stack->array[i].name) == 0){
			stack->array[i].type = type;
		}
	}
}

void yyerror(const char* mens){
	printf("Error sintáctico en linea %i: %s\n", numlin, mens);
	exit(-1);
}

char* notImplemented(){
	char* error = "Not implemented yet";
	return error;
}

void reduceScope(){
	int i;
	for (i = stack->top; i >= 0; i--){
		if (stack->array[i].scope == currentScope) stack->top--;
	}
}

struct symbol getSymbol(char* varName){
	int i;
	for (i = 0; i <= stack->top; i++){
		if (strcmp(varName, stack->array[i].name) == 0){
			return stack->array[i];
		}
	}
	struct symbol a;
	a.type = -1;
	return a;
}
  
// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct Stack* createStack(unsigned capacity) { 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (struct symbol*) malloc(stack->capacity * sizeof(struct symbol)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
/*int isFull(struct Stack* stack) 
{   return stack->top == stack->capacity - 1; } 
  */
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{   return stack->top == -1;  } 

// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, struct symbol item) 
{ 
    /*if (isFull(stack)) 
        return; */
    stack->array[++stack->top] = item; 
    //printf("%s, %i, %s pushed to stack\n", item.name, item.type, item.value); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
void pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)){		
    	stack->top--; 
	}
}

void removeScope(struct Stack* stack){
	while(currentScope==stack->array[stack->top].scope){
		stack->top--;
	}
} 

