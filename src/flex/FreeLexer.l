%{
#include "Types.hpp"
%}

%option noyywrap
%option noinput
%option nounput

%x BEGIN_INT8 BEGIN_INT16 BEGIN_INT32 BEGIN_FLOAT BEGIN_DOBULE

%%

[ \t]										;
"\n"											{ return EOL; }
"int8("										{ BEGIN(BEGIN_INT8); }
"int16("									{ BEGIN(BEGIN_INT16); }
"int32("									{ BEGIN(BEGIN_INT32); }
"float("									{ BEGIN(BEGIN_FLOAT); }
"double("									{ BEGIN(BEGIN_DOBULE); }

<BEGIN_INT8>[+-]?[0-9]+\)					{ BEGIN(INITIAL); return INT8; }
<BEGIN_INT16>[+-]?[0-9]+\)					{ BEGIN(INITIAL); return INT16; }
<BEGIN_INT32>[+-]?[0-9]+\)					{ BEGIN(INITIAL); return INT32; }
<BEGIN_FLOAT>[+-]?[0-9]+\.[0-9]+\)			{ BEGIN(INITIAL); return FLOAT; }
<BEGIN_DOBULE>[+-]?[0-9]+\.[0-9]+\)			{ BEGIN(INITIAL); return DOUBLE; }

push										{ return PUSH; }
pop											{ return POP; }
dump										{ return DUMP; }
assert										{ return ASSERT; }
add											{ return ADD; }
sub											{ return SUB; }
mul											{ return MUL; }
div											{ return DIV; }
mod											{ return MOD; }
print										{ return PRINT; }
exit										{ return EXIT; }
^;;$										{ return END_OF_FILE; }
;.*											;
.											{ return ERROR; }

%%
