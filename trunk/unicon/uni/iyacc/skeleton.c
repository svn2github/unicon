#include "defs.h"

/*  The definition of yysccsid in the banner should be replaced with	*/
/*  a #pragma ident directive if the target C compiler supports		*/
/*  #pragma ident directives.						*/
/*									*/
/*  If the skeleton is changed, the banner should be changed so that	*/
/*  the altered version can be easily distinguished from the original.	*/
/*									*/
/*  The #defines included with the banner are there because they are	*/
/*  useful in subsequent code.  The macros #defined in the header or	*/
/*  the body either are not useful outside of semantic actions or	*/
/*  are conditional.							*/

char *banner[] =
{
    "#ifndef lint",
    "static char yysccsid[] = \"@(#)yaccpar	1.9 (Berkeley) 02/21/93\";",
    "#endif",
    "#define YYBYACC 1",
    "#define YYMAJOR 1",
    "#define YYMINOR 9",
    "#define yyclearin (yychar=(-1))",
    "#define yyerrok (yyerrflag=0)",
    "#define YYRECOVERING (yyerrflag!=0)",
     0
};

char *jbanner[] =
{
    "//### This file created by BYACC 1.9(/Java extension  0.9)",
    "//### (Berkeley) 02/21/93", 
    "//### Java capabilities added 7 Jan 97, Bob Jamison",
    "//### Updated : 27 Nov 97  -- Bob Jamison, Joe Nieten",
    "//###           Updateed to JDK1.1 and added LVAL type",
    "//### Please send bug reports to rjamison@lincom-asg.com",
    "\n\n",
    0
};

char *ibanner[] =
{
    "### This file created by IYACC 1.0",
    "### Please send bug reports to raypereda@hotmail.com",
    0
};


char *tables[] =
{
    "extern short yylhs[];",
    "extern short yylen[];",
    "extern short yydefred[];",
    "extern short yydgoto[];",
    "extern short yysindex[];",
    "extern short yyrindex[];",
    "extern short yygindex[];",
    "extern short yytable[];",
    "extern short yycheck[];",
    "#if YYDEBUG",
    "extern char *yyname[];",
    "extern char *yyrule[];",
    "#endif",
    0
};

char *jtables[] =
{
    "extern short yylhs[];",
    0
};


char *itables[] =
{
    "global yylhs",
    "global yylen",
    "global yydefred",
    "global yydgoto",
    "global yysindex",
    "global yyrindex",
    "global yygindex",
    "global yytable",
    "global yycheck",
    "global yyname",
    "global yyrule",
    0
};



char *header[] =
{
    "#ifdef YYSTACKSIZE",
    "#undef YYMAXDEPTH",
    "#define YYMAXDEPTH YYSTACKSIZE",
    "#else",
    "#ifdef YYMAXDEPTH",
    "#define YYSTACKSIZE YYMAXDEPTH",
    "#else",
    "#define YYSTACKSIZE 500",
    "#define YYMAXDEPTH 500",
    "#endif",
    "#endif",
    "int yydebug;",
    "int yynerrs;",
    "int yyerrflag;",
    "int yychar;",
    "short *yyssp;",
    "YYSTYPE *yyvsp;",
    "YYSTYPE yyval;",
    "YYSTYPE yylval;",
    "short yyss[YYSTACKSIZE];",
    "YYSTYPE yyvs[YYSTACKSIZE];",
    "#define yystacksize YYSTACKSIZE",
    0
};

char *jheader[] =
{
  "\n\n\n",
  "//#####################################################################",
  "@JAVA@// class: %s\n",
  "// does : encapsulates yacc() parser functionality in a Java",
  "//        class for quick code development",
  "//#####################################################################",
  "@JAVAX@public class %s extends %s\n",
  "{\n",
  "boolean yydebug;        //do I want debug output?",
  "int yynerrs;            //number of errors so far",
  "int yyerrflag;          //was there an error?",
  "int yychar;             //the current working character",
  "\n//########## MESSAGES ##########",
  "//###############################################################",
  "// method: debug",
  "//###############################################################",
  "void debug(String msg)",
  "{",
  "  if (yydebug)",
  "    System.out.println(msg);",
  "}",
  "\n//########## STATE STACK ##########",
  "final static int YYSTACKSIZE = 500;  //maximum stack size",
  "int statestk[],stateptr;             //state stack",
  "//###############################################################",
  "// methods: state stack push,pop,drop,peek",
  "//###############################################################",
  "void state_push(int state)",
  "{",
  "  if (stateptr>=YYSTACKSIZE)         //overflowed?",
  "    return;",
  "  statestk[++stateptr]=state;",
  "}",
  "int state_pop()",
  "{",
  "  if (stateptr<0)                    //underflowed?",
  "    return -1;",
  "  return statestk[stateptr--];",
  "}",
  "void state_drop(int cnt)",
  "{",
  "int ptr;",
  "  ptr=stateptr-cnt;",
  "  if (ptr<0)",
  "    return;",
  "  stateptr = ptr;",
  "}",
  "int state_peek(int relative)",
  "{",
  "int ptr;",
  "  ptr=stateptr-relative;",
  "  if (ptr<0)",
  "    return -1;",
  "  return statestk[ptr];",
  "}",
  "//###############################################################",
  "// method: init_stacks : allocate and prepare stacks",
  "//###############################################################",
  "boolean init_stacks()",
  "{",
  "  statestk = new int[YYSTACKSIZE];",
  "  stateptr = -1;",
  "  val_init();",
  "  return true;",
  "}",
  "//###############################################################",
  "// method: dump_stacks : show n levels of the stacks",
  "//###############################################################",
  "void dump_stacks(int count)",
  "{",
  "int i;",
  "  System.out.println(\"=index==state====value=     s:\"+stateptr+\"  v:\"+valptr);",
  "  for (i=0;i<count;i++)",
  "    System.out.println(\" \"+i+\"    \"+statestk[i]+\"      \"+valstk[i]);",
  "  System.out.println(\"======================\");",
  "}",
  0
};


char *iheader[] =
{
  "#####################################################################",
  "#####################################################################",
  "invocable all    # need to look up semantic actions by name",
  "",
  "global yytext    # user variable to return contextual strings",
  "global yyval     # used to return semantic vals from action routines",
  "global yylval    # the 'lval' (result) I got from yylex()",
  "global yydebug   # (boolean) do I want debug output?",
  "global yynerrs   # (integer) number of errors so far",
  "global yyerrflag # (integer) was there an error?",
  "global yychar    # (integer) the current working character",
  "global action    # maps an integer to a semantic action procedure",
  "",
  "global yylhs",
  "global yylen",
  "global yydefred",
  "global yydgoto",
  "global yysindex",
  "global yyrindex",
  "global yygindex",
  "global yytable",
  "global yycheck",
  "global yyname",
  "global yyrule",
  "",
  "global statestk         # state stack",
  "global valstk           # value stack",
/*
  "################################################################",
  "# procedure: debug",
  "################################################################",
  "procedure debug(msg[])",
  "  msg := [&errout, \"line \", msg[1], \": \"] ||| msg[2:0]",
  "  write!msg ",
  "end",
  "",
*/
  "################################################################",
  "# procedure: init_stacks : allocate and prepare stacks",
  "################################################################",
  "procedure init_stacks()",
  "  local i",
  "  statestk := []",
  "  valstk := []",
  "  yyval  := 0 ",
  "  yylval := 0 ",
  "  action := list(1000, action_null)  # remove hard coded 1000 later",
  "  every i := 1 to 1000 do action[i] := proc(\"action_\" || i)",
  "end",
  "",
/*
  "################################################################",
  "# procedure: dump_stacks : show n levels of the stacks",
  "################################################################",
  "procedure dump_stacks(count)",
  "  local i ",
  "  write(\"=index==state====value=     s:\" || *statestk || \"  v:\" || *valstk) ",
  "  every i := 1 to count do",
  "    write(\" \" || i || \"    \" || statestk[i] || \"      \" || valstk[i]) ",
  "  write(\"======================\") ",
  "end",
  "",
*/
  0
};


char *body[] =
{
    "#define YYABORT goto yyabort",
    "#define YYREJECT goto yyabort",
    "#define YYACCEPT goto yyaccept",
    "#define YYERROR goto yyerrlab",
    "int",
    "yyparse()",
    "{",
    "    register int yym, yyn, yystate;",
    "#if YYDEBUG",
    "    register char *yys;",
    "    extern char *getenv();",
    "",
    "    if (yys = getenv(\"YYDEBUG\"))",
    "    {",
    "        yyn = *yys;",
    "        if (yyn >= '0' && yyn <= '9')",
    "            yydebug = yyn - '0';",
    "    }",
    "#endif",
    "",
    "    yynerrs = 0;",
    "    yyerrflag = 0;",
    "    yychar = (-1);",
    "",
    "    yyssp = yyss;",
    "    yyvsp = yyvs;",
    "    *yyssp = yystate = 0;",
    "",
    "yyloop:",
    "    if (yyn = yydefred[yystate]) goto yyreduce;",
    "    if (yychar < 0)",
    "    {",
    "        if ((yychar = yylex()) < 0) yychar = 0;",
    "#if YYDEBUG",
    "        if (yydebug)",
    "        {",
    "            yys = 0;",
    "            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];",
    "            if (!yys) yys = \"illegal-symbol\";",
    "            printf(\"%sdebug: state %d, reading %d (%s)\\n\",",
    "                    YYPREFIX, yystate, yychar, yys);",
    "        }",
    "#endif",
    "    }",
    "    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&",
    "            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)",
    "    {",
    "#if YYDEBUG",
    "        if (yydebug)",
    "            printf(\"%sdebug: state %d, shifting to state %d\\n\",",
    "                    YYPREFIX, yystate, yytable[yyn]);",
    "#endif",
    "        if (yyssp >= yyss + yystacksize - 1)",
    "        {",
    "            goto yyoverflow;",
    "        }",
    "        *++yyssp = yystate = yytable[yyn];",
    "        *++yyvsp = yylval;",
    "        yychar = (-1);",
    "        if (yyerrflag > 0)  --yyerrflag;",
    "        goto yyloop;",
    "    }",
    "    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&",
    "            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)",
    "    {",
    "        yyn = yytable[yyn];",
    "        goto yyreduce;",
    "    }",
    "    if (yyerrflag) goto yyinrecovery;",
    "#ifdef lint",
    "    goto yynewerror;",
    "#endif",
    "yynewerror:",
    "    yyerror(\"syntax error\");",
    "#ifdef lint",
    "    goto yyerrlab;",
    "#endif",
    "yyerrlab:",
    "    ++yynerrs;",
    "yyinrecovery:",
    "    if (yyerrflag < 3)",
    "    {",
    "        yyerrflag = 3;",
    "        for (;;)",
    "        {",
    "            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&",
    "                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)",
    "            {",
    "#if YYDEBUG",
    "                if (yydebug)",
    "                    printf(\"%sdebug: state %d, error recovery shifting\\",
    " to state %d\\n\", YYPREFIX, *yyssp, yytable[yyn]);",
    "#endif",
    "                if (yyssp >= yyss + yystacksize - 1)",
    "                {",
    "                    goto yyoverflow;",
    "                }",
    "                *++yyssp = yystate = yytable[yyn];",
    "                *++yyvsp = yylval;",
    "                goto yyloop;",
    "            }",
    "            else",
    "            {",
    "#if YYDEBUG",
    "                if (yydebug)",
    "                    printf(\"%sdebug: error recovery discarding state %d\
\\n\",",
    "                            YYPREFIX, *yyssp);",
    "#endif",
    "                if (yyssp <= yyss) goto yyabort;",
    "                --yyssp;",
    "                --yyvsp;",
    "            }",
    "        }",
    "    }",
    "    else",
    "    {",
    "        if (yychar == 0) goto yyabort;",
    "#if YYDEBUG",
    "        if (yydebug)",
    "        {",
    "            yys = 0;",
    "            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];",
    "            if (!yys) yys = \"illegal-symbol\";",
    "            printf(\"%sdebug: state %d, error recovery discards token %d\
 (%s)\\n\",",
    "                    YYPREFIX, yystate, yychar, yys);",
    "        }",
    "#endif",
    "        yychar = (-1);",
    "        goto yyloop;",
    "    }",
    "yyreduce:",
    "#if YYDEBUG",
    "    if (yydebug)",
    "        printf(\"%sdebug: state %d, reducing by rule %d (%s)\\n\",",
    "                YYPREFIX, yystate, yyn, yyrule[yyn]);",
    "#endif",
    "    yym = yylen[yyn];",
    "    yyval = yyvsp[1-yym];",
    "    switch (yyn)",
    "    {",
    0
};

char *jbody[] =
{
    "//###############################################################",
    "// method: yylexdebug : check lexer state",
    "//###############################################################",
    "void yylexdebug(int state,int ch)",
    "{",
    "String s=null;",
    "  if (ch < 0) ch=0;",
    "  if (ch <= YYMAXTOKEN) //check index bounds",
    "     s = yyname[ch];    //now get it",
    "  if (s==null)",
    "    s = \"illegal-symbol\";",
    "  debug(\"state \"+state+\", reading \"+ch+\" (\"+s+\")\");",
    "}\n\n\n",
    "//###############################################################",
    "// method: yyparse : parse input and execute indicated items",
    "//###############################################################",
    "int yyparse()",
    "{",
    "int yyn;       //next next thing to do",
    "int yym;       //",
    "int yystate;   //current parsing state from state table",
    "String yys;    //current token string",
    "boolean doaction;",
    "  init_stacks();",
    "  yynerrs = 0;",
    "  yyerrflag = 0;",
    "  yychar = -1;          //impossible char forces a read",
    "  yystate=0;            //initial state",
    "  state_push(yystate);  //save it",
    "  while (true) //until parsing is done, either correctly, or w/error",
    "    {",
    "    doaction=true;",
    "    if (yydebug) debug(\"loop\"); ",
    "    //#### NEXT ACTION (from reduction table)",
    "    for (yyn=yydefred[yystate];yyn==0;yyn=yydefred[yystate])",
    "      {",
    "      if (yydebug) debug(\"yyn:\"+yyn+\"  state:\"+yystate+\"  char:\"+yychar);",
    "      if (yychar < 0)      //we want a char?",
    "        {",
    "        yychar = yylex();  //get next token",
    "        //#### ERROR CHECK ####",
    "        if (yychar < 0)    //it it didn't work/error",
    "          {",
    "          yychar = 0;      //change it to default string (no -1!)",
    "          if (yydebug)",
    "            yylexdebug(yystate,yychar);",
    "          }",
    "        }//yychar<0",
    "      yyn = yysindex[yystate];  //get amount to shift by (shift index)",
    "      if ((yyn != 0) && (yyn += yychar) >= 0 &&",
    "          yyn <= YYTABLESIZE && yycheck[yyn] == yychar)",
    "        {",
    "        if (yydebug)",
    "          debug(\"state \"+yystate+\", shifting to state \"+yytable[yyn]+\"\");",
    "        //#### NEXT STATE ####",
    "        yystate = yytable[yyn];//we are in a new state",
    "        state_push(yystate);   //save it",
    "        val_push(yylval);      //push our lval as the input for next rule",
    "        yychar = -1;           //since we have 'eaten' a token, say we need another",
    "        if (yyerrflag > 0)     //have we recovered an error?",
    "           --yyerrflag;        //give ourselves credit",
    "        doaction=false;        //but don't process yet",
    "        break;   //quit the yyn=0 loop",
    "        }",
    "",
    "    yyn = yyrindex[yystate];  //reduce",
    "    if ((yyn !=0 ) && (yyn += yychar) >= 0 &&",
    "            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)",
    "      {   //we reduced!",
    "      if (yydebug) debug(\"reduce\");",
    "      yyn = yytable[yyn];",
    "      doaction=true; //get ready to execute",
    "      break;         //drop down to actions",
    "      }",
    "    else //ERROR RECOVERY",
    "      {",
    "      if (yyerrflag==0)",
    "        {",
    "        yyerror(\"syntax error\");",
    "        yynerrs++;",
    "        }",
    "      if (yyerrflag < 3) //low error count?",
    "        {",
    "        yyerrflag = 3;",
    "        while (true)   //do until break",
    "          {",
    "          if (stateptr<0)   //check for under & overflow here",
    "            {",
    "            yyerror(\"stack underflow. aborting...\");  //note lower case 's'",
    "            return 1;",
    "            }",
    "          yyn = yysindex[state_peek(0)];",
    "          if ((yyn != 0) && (yyn += YYERRCODE) >= 0 &&",
    "                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)",
    "            {",
    "            if (yydebug)",
    "              debug(\"state \"+state_peek(0)+\", error recovery shifting to state \"+yytable[yyn]+\" \");",
    "            yystate = yytable[yyn];",
    "            state_push(yystate);",
    "            val_push(yylval);",
    "            doaction=false;",
    "            break;",
    "            }",
    "          else",
    "            {",
    "            if (yydebug)",
    "              debug(\"error recovery discarding state \"+state_peek(0)+\" \");",
    "            if (stateptr<0)   //check for under & overflow here",
    "              {",
    "              yyerror(\"Stack underflow. aborting...\");  //capital 'S'",
    "              return 1;",
    "              }",
    "            state_pop();",
    "            val_pop();",
    "            }",
    "          }",
    "        }",
    "      else            //discard this token",
    "        {",
    "        if (yychar == 0)",
    "          return 1; //yyabort",
    "        if (yydebug)",
    "          {",
    "          yys = null;",
    "          if (yychar <= YYMAXTOKEN) yys = yyname[yychar];",
    "          if (yys == null) yys = \"illegal-symbol\";",
    "          debug(\"state \"+yystate+\", error recovery discards token \"+yychar+\" (\"+yys+\")\");",
    "          }",
    "        yychar = -1;  //read another",
    "        }",
    "      }//end error recovery",
    "    }//yyn=0 loop",
    "    if (!doaction)   //any reason not to proceed?",
    "      continue;      //skip action",
    "    yym = yylen[yyn];          //get count of terminals on rhs",
    "    if (yydebug)",
    "      debug(\"state \"+yystate+\", reducing \"+yym+\" by rule \"+yyn+\" (\"+yyrule[yyn]+\")\");",
    "    yyval = val_peek(yym-1);   //get current semantic value",
    "    switch(yyn)",
    "      {",
    "//########## USER-SUPPLIED ACTIONS ##########",
    0
};

char *ibody[] =
{
/*
    "################################################################",
    "# procedure: yylexdebug : check lexer state",
    "################################################################",
    "procedure yylexdebug(state,ch)",
    "  local s ",
    "  if ch < 0 then ch := 0 ",
    "  if ch <= YYMAXTOKEN then  # check index bounds",
    "     s := yyname[ch+1]      # now get it",
    "  if integer(s) & s = 0 then s := \"illegal-symbol\" ",
    "  debug(&line, \"state \", state, \", reading \", ch, \" (\", s, \")\") ",
    "end",
    "",
    "",
*/
    "################################################################",
    "# procedure: yyparse : parse input and execute indicated items",
    "################################################################",
    "procedure yyparse()",
    "  local yyn        # next next thing to do",
    "  local yym        #",
    "  local yystate    # current parsing state from state table",
    "  local yys        # current token string",
    "  local doaction   # set to 1 if there need to execute action",
    "  local token      # current token",
    "",
    "  if /yytable then init() ",
    "  init_stacks() ",
    "  yynerrs   := 0 ",
    "  yyerrflag := 0 ",
    "  yychar    := -1           # impossible char forces a read",
    "  yystate   := 0            # initial state",
    "  push(statestk, yystate)   # save it",
    "",
    "  repeat { # until parsing is done, either correctly, or w/error",
    "    doaction := 1 ",
/*    "    debug(&line, \"loop\")  ", */
    "",
    "    ##### NEXT ACTION (from reduction table)",
    "	yyn := yydefred[yystate+1]",
/*    "	debug(&line, \"yyn: \", yyn)", */
    "",
    "    while yyn = 0 do {",
/*    "      debug(&line, \"yyn:\", yyn, \"  state:\", yystate, \"  char:\", yychar) ", */
    "",
    "      if yychar < 0 then {   # we want a char?",
    "        yychar := yylex()    # get next token",
    "        ##### ERROR CHECK ####",
    "        if yychar < 0 then { # it it didn't work/error",
    "          yychar := 0        # change it to default string (no -1!)",
    "          if \\yydebug = 1 then yylexdebug(yystate, yychar) ",
    "          }",
    "        } # yychar < 0",
    "	  ",
    "      yyn := yysindex[yystate+1]  # get amount to shift by (shift index)",
    "",
    "      if (yyn ~= 0)           & ((yyn +:= yychar) >= 0) & ",
    "         (yyn <= YYTABLESIZE) & (yycheck[yyn+1] = yychar) then {",
    "		",
/*    "        debug(&line, \"state \", yystate, \", shifting to state \", yytable[yyn+1], \"\") ", */
    "        ##### NEXT STATE ####",
    "        yystate := yytable[yyn+1] # we are in a new state",
    "        push(statestk, yystate)   # save it",
    "        push(valstk, yylval)      # push our lval as the input for next rule",
    "        yychar := -1              # since we have 'eaten' a token, say we need another",
    "        if yyerrflag > 0 then     # have we recovered an error?",
    "           yyerrflag -:= 1        # give ourselves credit",
    "        doaction := 0             # but don't process yet",
    "        break                     # quit the yyn=0 loop",
    "        }",
    "",
    "    yyn := yyrindex[yystate+1]    # reduce",
    "",
/*  
    "    debug(&line, \"yyn: \", yyn)",
    "	 debug(&line, \"yychar: \", yychar)",
    "	 debug(&line, \"yycheck[yyn+yychar+1]:\", yycheck[yyn+yychar+1])",
    "",
*/
    "    if (yyn ~= 0)           & ((yyn +:= yychar) >= 0) &",
    "       (yyn <= YYTABLESIZE) & (yycheck[yyn+1] = yychar) then {",
    "      # e reduced!",
/*    "      debug(&line, \"reduce\") ", */
    "      yyn      := yytable[yyn+1] ",
    "      doaction := 1  # get ready to execute",
    "      break          # drop down to actions",
    "      }",
    "    else { #ERROR RECOVERY",
    "      if yyerrflag == 0 then {",
    "        (\\yyerror | write)(\"syntax error\") ",
    "        yynerrs +:= 1 ",
    "      }",
    "      if yyerrflag < 3 then {     # low error count?",
    "        yyerrflag := 3 ",
    "        repeat { #do until break",
    "          if *statestk < 1 then {  # check for under & overflow here",
    "            (\\yyerror | write)(\"stack underflow. aborting...\")   # note lower case 's'",
    "            return 1 ",
    "          }",
    "          yyn := yysindex[statestk[1]] ",
    "          if ((yyn ~= 0) & (yyn +:= YYERRCODE) >= 0 &",
    "                    yyn <= YYTABLESIZE & yycheck[yyn+1] == YYERRCODE) then {",
/*    "            debug(&line, \"state \", statestk[1], ", */
/*    "                  \", error recovery shifting to state \", yytable[yyn], " ") ", */
    "            yystate := yytable[yyn+1] ",
    "            push(statestk, yystate) ",
    "            push(valstk, yylval) ",
    "            doaction := 0 ",
    "            break ",
    "          }",
    "          else {",
/*    "            debug(&line, \"error recovery discarding state \", statestk[1], \" \") ", */
    "            if *statestk = 0 then { # check for under & overflow here",
    "              write(\"Stack underflow. aborting...\") # capital 'S'",
    "              return 1 ",
    "            }",
    "            pop(statestk) ",
    "            pop(valstk) ",
    "            }",
    "          }",
    "        }",
    "      else  # discard this token",
    "        {",
    "        if yychar = 0 then return 1  # yyabort",
    "        if \\yydebug = 1 then {",
    "          yys := &null ",
    "          if yychar <= YYMAXTOKEN then yys := yyname[yychar+1] ",
    "          if integer(yys) & yys = 0 then yys := \"illegal-symbol\" ",
    "          write(\"state \",  yystate, \", error recovery discards token \",",
    "                yychar, \" (\", yys, \")\") ",
    "          }",
    "        yychar := -1       # read another",
    "        }",
    "      } # end error recovery",
    "      yyn := yydefred[yystate+1] ",
    "    }# yyn = 0 loop",
    "",
/*
    "    debug(&line, \"at the end of yyn = 0 loop\")", 
    "",
*/
    "    if doaction = 0 then   # any reason not to proceed?",
    "      next                 # skip action",
    "",
    "    yym := yylen[yyn+1]    # get count of terminals on rhs",
/*
    "    debug(&line, \"state \", yystate, \", reducing \", yym, \" by rule \",",
    "           yyn, \" (\", yyrule[yyn+1], \")\") ",
*/
    "    yyval := valstk[yym]   # get current semantic value",
	"    action[yyn]()          # execute the semantic action",
	"",
/*    "    case yyn of {",
    "########### USER-SUPPLIED ACTIONS ##########", 
*/
    0
};

char *trailer[] =
{
    "    }",
    "    yyssp -= yym;",
    "    yystate = *yyssp;",
    "    yyvsp -= yym;",
    "    yym = yylhs[yyn];",
    "    if (yystate == 0 && yym == 0)",
    "    {",
    "#if YYDEBUG",
    "        if (yydebug)",
    "            printf(\"%sdebug: after reduction, shifting from state 0 to\\",
    " state %d\\n\", YYPREFIX, YYFINAL);",
    "#endif",
    "        yystate = YYFINAL;",
    "        *++yyssp = YYFINAL;",
    "        *++yyvsp = yyval;",
    "        if (yychar < 0)",
    "        {",
    "            if ((yychar = yylex()) < 0) yychar = 0;",
    "#if YYDEBUG",
    "            if (yydebug)",
    "            {",
    "                yys = 0;",
    "                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];",
    "                if (!yys) yys = \"illegal-symbol\";",
    "                printf(\"%sdebug: state %d, reading %d (%s)\\n\",",
    "                        YYPREFIX, YYFINAL, yychar, yys);",
    "            }",
    "#endif",
    "        }",
    "        if (yychar == 0) goto yyaccept;",
    "        goto yyloop;",
    "    }",
    "    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&",
    "            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)",
    "        yystate = yytable[yyn];",
    "    else",
    "        yystate = yydgoto[yym];",
    "#if YYDEBUG",
    "    if (yydebug)",
    "        printf(\"%sdebug: after reduction, shifting from state %d \\",
    "to state %d\\n\", YYPREFIX, *yyssp, yystate);",
    "#endif",
    "    if (yyssp >= yyss + yystacksize - 1)",
    "    {",
    "        goto yyoverflow;",
    "    }",
    "    *++yyssp = yystate;",
    "    *++yyvsp = yyval;",
    "    goto yyloop;",
    "yyoverflow:",
    "    fprintf(stderr, \"yacc stack overflow\\n\");",
    "yyabort:",
    "    return (1);",
    "yyaccept:",
    "    return (0);",
    "}",
    0
};

char *jtrailer[] =
{
    "//########## END OF USER-SUPPLIED ACTIONS ##########",
    "    }//switch",
    "    //#### Now let's reduce... ####",
    "    if (yydebug) debug(\"reduce\");",
    "    state_drop(yym);             //we just reduced yylen states",
    "    yystate = state_peek(0);     //get new state",
    "    val_drop(yym);               //corresponding value drop",
    "    yym = yylhs[yyn];            //select next TERMINAL(on lhs)",
    "    if (yystate == 0 && yym == 0)//done? 'rest' state and at first TERMINAL",
    "      {",
    "      debug(\"After reduction, shifting from state 0 to state \"+YYFINAL+\"\");",
    "      yystate = YYFINAL;         //explicitly say we're done",
    "      state_push(YYFINAL);       //and save it",
    "      val_push(yyval);           //also save the semantic value of parsing",
    "      if (yychar < 0)            //we want another character?",
    "        {",
    "        yychar = yylex();        //get next character",
    "        if (yychar<0) yychar=0;  //clean, if necessary",
    "        if (yydebug)",
    "          yylexdebug(yystate,yychar);",
    "        }",
    "      if (yychar == 0)          //Good exit (if lex returns 0 ;-)",
    "         break;                 //quit the loop--all DONE",
    "      }//if yystate",
    "    else                        //else not done yet",
    "      {                         //get next state and push, for next yydefred[]",
    "      yyn = yygindex[yym];      //find out where to go",
    "      if ((yyn != 0) && (yyn += yystate) >= 0 &&",
    "            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)",
    "        yystate = yytable[yyn]; //get new state",
    "      else",
    "        yystate = yydgoto[yym]; //else go to new defred",
    "      debug(\"after reduction, shifting from state \"+state_peek(0)+\" to state \"+yystate+\"\");",
    "      state_push(yystate);     //going again, so push state & val...",
    "      val_push(yyval);         //for next action",
    "      }",
    "    }//main loop",
    "  return 0;//yyaccept!!",
    "}",
    "//## end of method parse() ######################################",
    "\n\n",
    "//## run() --- for Thread #######################################",
    "public void run()",
    "{",
    "   yyparse();",
    "}",
    "//## end of method run() ########################################",
    "\n\n",
    "//## Constructor ################################################",
    "@JAVA@public %s()\n",
    "{",
    "}\n",
    "@JAVA@public %s(boolean debug_me)\n",
    "{",
    "  yydebug=debug_me;",
    "}",
    "//###############################################################",
    "\n\n",
    "}",
    "//################### END OF CLASS yaccpar ######################",
    0
};



char *itrailer[] =
{
/*    "########### END OF USER-SUPPLIED ACTIONS ##########",
    "}#case",
    "",
*/
    "    ##### Now let's reduce... ####",
/*    "    debug(&line, \"reduce\")  ", */
    "    every 1 to yym do pop(statestk)# we just reduced yylen states",
    "    yystate := statestk[1]        # get new state",
    "",
    "    every 1 to yym do pop(valstk) # corresponding value drop",
/*    "	 debug(&line, \"yyn: \", yyn)",
    "",
*/
    "    yym := yylhs[yyn+1]           # select next TERMINAL(on lhs)",
/*    "	 debug(&line, \"yym: \", yym)",
    "",
*/
    "    if yystate = 0 & yym = 0 then {",
    "                                  # done? 'rest' state and at first TERMINAL",
/*    "      debug(&line, \"After reduction, shifting from state 0 to state \", YYFINAL, \"\") ", */
    "      yystate := YYFINAL          # explicitly say we're done",
    "      push(statestk, YYFINAL)     # and save it",
    "      push(valstk, yyval)         # also save the semantic value of parsing",
    "      if yychar < 0 then {        # we want another character?",
    "        yychar := yylex()         # get next character",
    "        if yychar < 0 then yychar := 0   #clean, if necessary",
/*    "        yylexdebug(yystate, yychar) ", */
    "      }",
    "      if yychar = 0 then break    # Good exit (if lex returns 0  -)",
    "                                  # quit the loop--all DONE",
    "    } # if yystate",
    "    else {                        #else not done yet",
    "      # get next state and push, for next yydefred[]",
/*
    "	   debug(&line, \"yyn: \", yyn)",
    "	   debug(&line, \"yym: \", yym)",
    "	   debug(&line, \"yygindex[yym]: \", yygindex[yym+1])",
    "",
*/
    "      yyn := yygindex[yym+1]        # find out where to go",
    "      if (yyn ~= 0)           & ((yyn +:= yystate) >= 0) &",
    "         (yyn <= YYTABLESIZE) & (yycheck[yyn+1] = yystate) then {",
    "        yystate := yytable[yyn+1]   # get new state",
    "        }",
    "      else {",
    "        yystate := yydgoto[yym+1]   # else go to new defred",
    "	     }",
/*
    "      debug(&line, \"after reduction, shifting from state \", ",
    "            state[1], \" to state \", yystate, \"\") ",
*/
    "      push(statestk, yystate)       # going again, so push state & val...",
    "      push(valstk, yyval)           # for next action",
    "      }",
    "    } # main loop",
    "",
    "  return 0 # yyaccept!!",
    "end",
    "",
    "### end of procedure parse() ######################################",
	"",
	"### start semantic actions ########################################",
	"",
	"procedure action_null()",
    "  #write(\"null action\")",
    "end",
    "", 
    0
};


char *jtrailer_nothread[] =
{
    "//########## END OF USER-SUPPLIED ACTIONS ##########",
    "    }//switch",
    "    //#### Now let's reduce... ####",
    "    if (yydebug) debug(\"reduce\");",
    "    state_drop(yym);             //we just reduced yylen states",
    "    yystate = state_peek(0);     //get new state",
    "    val_drop(yym);               //corresponding value drop",
    "    yym = yylhs[yyn];            //select next TERMINAL(on lhs)",
    "    if (yystate == 0 && yym == 0)//done? 'rest' state and at first TERMINAL",
    "      {",
    "      debug(\"After reduction, shifting from state 0 to state \"+YYFINAL+\"\");",
    "      yystate = YYFINAL;         //explicitly say we're done",
    "      state_push(YYFINAL);       //and save it",
    "      val_push(yyval);           //also save the semantic value of parsing",
    "      if (yychar < 0)            //we want another character?",
    "        {",
    "        yychar = yylex();        //get next character",
    "        if (yychar<0) yychar=0;  //clean, if necessary",
    "        if (yydebug)",
    "          yylexdebug(yystate,yychar);",
    "        }",
    "      if (yychar == 0)          //Good exit (if lex returns 0 ;-)",
    "         break;                 //quit the loop--all DONE",
    "      }//if yystate",
    "    else                        //else not done yet",
    "      {                         //get next state and push, for next yydefred[]",
    "      yyn = yygindex[yym];      //find out where to go",
    "      if ((yyn != 0) && (yyn += yystate) >= 0 &&",
    "            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)",
    "        yystate = yytable[yyn]; //get new state",
    "      else",
    "        yystate = yydgoto[yym]; //else go to new defred",
    "      debug(\"after reduction, shifting from state \"+state_peek(0)+\" to state \"+yystate+\"\");",
    "      state_push(yystate);     //going again, so push state & val...",
    "      val_push(yyval);         //for next action",
    "      }",
    "    }//main loop",
    "  return 0;//yyaccept!!",
    "}",
    "//## end of method parse() ######################################",
    "\n\n",
    "}",
    "//################### END OF CLASS yaccpar ######################",
    0
};

void write_section(char **section)
{
int i;
FILE *fp;
  fp = code_file;
  if (section==jtrailer)
    {
    if (strcmp(java_extend_name,"Thread")!=0)
      section=jtrailer_nothread;
    }
  for (i = 0; section[i]; ++i)
    {
	 ++outline;
    if (strncmp(section[i],"@JAVA@",6)==0)
	   fprintf(fp,&(section[i][6]),java_class_name);
    else if (strncmp(section[i],"@JAVAX@",7)==0)
	   fprintf(fp,&(section[i][7]),java_class_name,java_extend_name);
    else
	   fprintf(fp, "%s\n", section[i]);
    }
}




