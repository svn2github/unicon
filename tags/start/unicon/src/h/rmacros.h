/*
 *  Definitions for macros and manifest constants used in the compiler
 *  interpreter.
 */

/*
 *  Definitions common to the compiler and interpreter.
 */

/*
 * Constants that are not likely to vary between implementations.
 */

#define BitOffMask (IntBits-1)
#define CsetSize (256/IntBits)	/* number of ints to hold 256 cset
				 *  bits. Use (256/IntBits)+1 if
				 *  256 % IntBits != 0 */
#define MinListSlots	    8	/* number of elements in an expansion
				 * list element block  */

#define MaxCvtLen	   257	/* largest string in conversions; the extra
				 *  one is for a terminating null */
#define MaxReadStr	   512	/* largest string to read() in one piece */
#define MaxIn		  32767	/* largest number of bytes to read() at once */
#define RandA        1103515245	/* random seed multiplier */
#define RandC	      453816694	/* random seed additive constant */
#define RanScale 4.65661286e-10	/* random scale factor = 1/(2^31-1) */

#define Pi 3.14159265358979323846264338327950288419716939937511

/*
 * File status flags in status field of file blocks.
 */
#define Fs_Read		 01	/* read access */
#define Fs_Write	 02	/* write access */
#define Fs_Create	 04	/* file created on open */
#define Fs_Append	010	/* append mode */
#define Fs_Pipe		020	/* reading/writing on a pipe */

#ifdef RecordIO
   #define Fs_Record    040	/* record structured file */
#endif					/* RecordIO */

#define Fs_Reading     0100     /* last file operation was read */
#define Fs_Writing     0200     /* last file operation was write */

#ifdef Graphics
   #define Fs_Window   0400	/* reading/writing on a window */
#endif					/* Graphics */
   
#define Fs_Untrans    01000	/* untranslated mode file */

#ifdef Dbm
   #define Fs_Dbm       02000		/* a dbm file */
#endif					/* Dbm */

#ifdef PosixFns
   #define Fs_Dir	04000		/* readdir will be used */
   #define Fs_Socket    010000
   #define Fs_Buff      020000
   #define Fs_Unbuf     040000
#endif					/* PosixFns */

#ifdef Network
   #define Fs_Network   0100000
#endif

#ifdef ISQL
   #define Fs_ODBC      0200000
   #define RC_SUCCESSFUL(rc) (rc==SQL_SUCCESS || rc==SQL_SUCCESS_WITH_INFO)
   #define RC_NOTSUCCESSFUL(rc) (!(RC_SUCCESSFUL(rc)))
#endif					/* ISQL */

#ifdef Messaging
   #define Fs_Messaging 0400000
#endif                                  /* Messaging */

#ifdef Graphics
   #define XKey_Window 0
   #define XKey_Fg 1
   
   #ifndef SHORT
      #define SHORT int
   #endif				/* SHORT */
   #ifndef LONG
      #define LONG int
   #endif				/* LONG */
   
   /*
    * Perform a "C" return, not processed by RTT
    */
   #define VanquishReturn(s) return s;
#endif					/* Graphics */

/*
 * Codes returned by runtime support routines.
 *  Note, some conversion routines also return type codes. Other routines may
 *  return positive values other than return codes. sort() places restrictions
 *  on Less, Equal, and Greater.
 */

#define Less		-1
#define Equal		0
#define Greater		1

#define CvtFail		-2
#define Cvt		-3
#define NoCvt		-4
#define Failed		-5
#define Defaulted	-6
#define Succeeded	-7
#define Error		-8

#define GlobalName	0
#define StaticName	1
#define ParamName	2
#define LocalName	3

#undef ToAscii
#undef FromAscii
#if EBCDIC == 2
   #define ToAscii(e) (FromEBCDIC[e])
   #define FromAscii(e) (ToEBCDIC[e])
#else					/* EBCDIC == 2 */
   #define ToAscii(e) (e)
   #define FromAscii(e) (e)
#endif					/* EBCDIC == 2 */

/*
 * Pointer to block.
 */
#define BlkLoc(d)	((d).vword.bptr)

/*
 * Check for null-valued descriptor.
 */
#define ChkNull(d)	((d).dword==D_Null)

/*
 * Check for equivalent descriptors.
 */
#define EqlDesc(d1,d2)	((d1).dword == (d2).dword && BlkLoc(d1) == BlkLoc(d2))

/*
 * Integer value.
 */
#define IntVal(d)	((d).vword.integr)

/*
 * Offset from top of block to value of variable.
 */
#define Offset(d)	((d).dword & OffsetMask)

/*
 * Check for pointer.
 */
#define Pointer(d)	((d).dword & F_Ptr)

/*
 * Check for qualifier.
 */
#define Qual(d)		(!((d).dword & F_Nqual))

/*
 * Length of string.
 */
#define StrLen(q)	((q).dword)

/*
 * Location of first character of string.
 */
#define StrLoc(q)	((q).vword.sptr)

/*
 * Assign a C string to a descriptor. Assume it is reasonable to use the
 *   descriptor expression more than once, but not the string expression.
 */
#define AsgnCStr(d,s) (StrLoc(d) = (s), StrLen(d) = strlen(StrLoc(d)))

/*
 * Type of descriptor.
 */
#define Type(d)		(int)((d).dword & TypeMask)

/*
 * Check for variable.
 */
#define Var(d)		((d).dword & F_Var)

/*
 * Location of the value of a variable.
 */
#define VarLoc(d)	((d).vword.descptr)

/*
 *  Important note:  The code that follows is not strictly legal C.
 *   It tests to see if pointer p2 is between p1 and p3. This may
 *   involve the comparison of pointers in different arrays, which
 *   is not well-defined.  The casts of these pointers to unsigned "words"
 *   (longs or ints, depending) works with all C compilers and architectures
 *   on which Icon has been implemented.  However, it is possible it will
 *   not work on some system.  If it doesn't, there may be a "false
 *   positive" test, which is likely to cause a memory violation or a
 *   loop. It is not practical to implement Icon on a system on which this
 *   happens.
 */

#define InRange(p1,p2,p3) ((uword)(p2) >= (uword)(p1) && (uword)(p2) < (uword)(p3))

/*
 * Get floating-point number from real block.
 */
#ifdef Double
   #define GetReal(dp,res) *((struct size_dbl *)&(res)) =\
         *((struct size_dbl *)&(BlkLoc(*dp)->realblk.realval))
#else					/* Double */
   #define GetReal(dp,res)	res = BlkLoc(*dp)->realblk.realval
#endif					/* Double */

/*
 * Absolute value, maximum, and minimum.
 */
#if (MVS || VM) && SASC
   #define Abs(x) __builtin_abs(x)
   #define Max(x,y)     __builtin_max(x,y)
   #define Min(x,y)     __builtin_min(x,y)
#else					/* SASC */
   #define Abs(x) (((x) < 0) ? (-(x)) : (x))
   #define Max(x,y)        ((x)>(y)?(x):(y))
   #define Min(x,y)        ((x)<(y)?(x):(y))
#endif					/* SASC */

/*
 * Number of elements of a C array, and element size.
 */
#define ElemCount(a) (sizeof(a)/sizeof(a[0]))
#define ElemSize(a) (sizeof(a[0]))

/*
 * Some C compilers take '\n' and '\r' to be the same, so the
 *  following definitions are used.
 */
#if EBCDIC
   /*
    * Note that, in EBCDIC, "line feed" and "new line" are distinct
    *  characters.  Icon's use of "line feed" is really "new line" in
    *  C terms.
    */
   #define LineFeed '\n'	/* if really "line feed", that's 37 */
   #define CarriageReturn '\r'
#else					/* EBCDIC */
   #define LineFeed  10
   #define CarriageReturn 13
#endif					/* EBCDIC */

/*
 * Construct an integer descriptor.
 */
#define MakeInt(i,dp)		do { \
                 	 (dp)->dword = D_Integer; \
                         IntVal(*dp) = (word)(i); \
			 } while (0)

/*
 * Construct a string descriptor.
 */
#define MakeStr(s,len,dp)      do { \
                 	 StrLoc(*dp) = (s); \
                         StrLen(*dp) = (len); \
			 } while (0)

/*
 * Offset in word of cset bit.
 */
#define CsetOff(b)	((b) & BitOffMask)

/*
 * Set bit b in cset c.
 */
#define Setb(b,c)	(*CsetPtr(b,c) |= (01 << CsetOff(b)))

/*
 * Test bit b in cset c.
 */
#define Testb(b,c)	((*CsetPtr(b,c) >> CsetOff(b)) & 01)

/*
 * Check whether a set or table needs resizing.
 */
#define SP(p) ((struct b_set *)p)
#define TooCrowded(p) \
   ((SP(p)->size > MaxHLoad*(SP(p)->mask+1)) && (SP(p)->hdir[HSegs-1] == NULL))
#define TooSparse(p) \
   ((SP(p)->hdir[1] != NULL) && (SP(p)->size < MinHLoad*(SP(p)->mask+1)))

/*
 * Definitions and declarations used for storage management.
 */
#define F_Mark		0100000 	/* bit for marking blocks */

/*
 * Argument values for the built-in Icon user function "collect()".
 */
#define Static  1			/* collection is for static region */
#define Strings	2			/* collection is for strings */
#define Blocks	3			/* collection is for blocks */

/*
 * Get type of block pointed at by x.
 */
#define BlkType(x)   (*(word *)x)

/*
 * BlkSize(x) takes the block pointed to by x and if the size of
 *  the block as indicated by bsizes[] is nonzero it returns the
 *  indicated size; otherwise it returns the second word in the
 *  block contains the size.
 */
#define BlkSize(x) (bsizes[*(word *)x & ~F_Mark] ? \
		     bsizes[*(word *)x & ~F_Mark] : *((word *)x + 1))

/*
 * Here are the events we support (in addition to keyboard characters)
 */
#define MOUSELEFT	(-1)
#define MOUSEMID	(-2)
#define MOUSERIGHT	(-3)
#define MOUSELEFTUP	(-4)
#define MOUSEMIDUP	(-5)
#define MOUSERIGHTUP	(-6)
#define MOUSELEFTDRAG	(-7)
#define MOUSEMIDDRAG	(-8)
#define MOUSERIGHTDRAG	(-9)
#define RESIZED		(-10)
#define WINDOWCLOSED    (-11)
#define MOUSEMOVED      (-12)
#define LASTEVENTCODE	MOUSEMOVED

/*
 * Type codes (descriptors and blocks).
 */
#define T_String	-1	/* string -- for reference; not used */
#define T_Null		 0	/* null value */
#define T_Integer	 1	/* integer */

#ifdef LargeInts
   #define T_Lrgint	 2	/* long integer */
#endif					/* LargeInts */

#define T_Real		 3	/* real number */
#define T_Cset		 4	/* cset */
#define T_File		 5	/* file */
#define T_Proc		 6	/* procedure */
#define T_Record	 7	/* record */
#define T_List		 8	/* list header */
#define T_Lelem		 9	/* list element */
#define T_Set		10	/* set header */
#define T_Selem		11	/* set element */
#define T_Table		12	/* table header */
#define T_Telem		13	/* table element */
#define T_Tvtbl		14	/* table element trapped variable */
#define T_Slots		15	/* set/table hash slots */
#define T_Tvsubs	16	/* substring trapped variable */
#define T_Refresh	17	/* refresh block */
#define T_Coexpr	18	/* co-expression */
#define T_External	19	/* external block */
#define T_Kywdint	20	/* integer keyword */
#define T_Kywdpos	21	/* keyword &pos */
#define T_Kywdsubj	22	/* keyword &subject */
#define T_Kywdwin	23	/* keyword &window */
#define T_Kywdstr	24	/* string keyword */
#define T_Kywdevent	25	/* keyword &eventsource, etc. */

#define MaxType		25	/* maximum type number */

/*
 * Definitions for keywords.
 */

#define k_pos kywd_pos.vword.integr	/* value of &pos */
#define k_random kywd_ran.vword.integr	/* value of &random */
#define k_trace kywd_trc.vword.integr	/* value of &trace */
#define k_dump kywd_dmp.vword.integr	/* value of &dump */

#ifdef FncTrace
   #define k_ftrace kywd_ftrc.vword.integr	/* value of &ftrace */
#endif					/* FncTrace */

/*
 * Descriptor types and flags.
 */

#define D_Null		(T_Null     | D_Typecode)
#define D_Integer	(T_Integer  | D_Typecode)

#ifdef LargeInts
   #define D_Lrgint	(T_Lrgint | D_Typecode | F_Ptr)
#endif					/* LargeInts */

#define D_Real		(T_Real     | D_Typecode | F_Ptr)
#define D_Cset		(T_Cset     | D_Typecode | F_Ptr)
#define D_File		(T_File     | D_Typecode | F_Ptr)
#define D_Proc		(T_Proc     | D_Typecode | F_Ptr)
#define D_List		(T_List     | D_Typecode | F_Ptr)
#define D_Lelem		(T_Lelem    | D_Typecode | F_Ptr)
#define D_Table		(T_Table    | D_Typecode | F_Ptr)
#define D_Telem		(T_Telem    | D_Typecode | F_Ptr)
#define D_Set		(T_Set      | D_Typecode | F_Ptr)
#define D_Selem		(T_Selem    | D_Typecode | F_Ptr)
#define D_Record	(T_Record   | D_Typecode | F_Ptr)
#define D_Tvsubs	(T_Tvsubs   | D_Typecode | F_Ptr | F_Var)
#define D_Tvtbl		(T_Tvtbl    | D_Typecode | F_Ptr | F_Var)
#define D_Kywdint	(T_Kywdint  | D_Typecode | F_Ptr | F_Var)
#define D_Kywdpos	(T_Kywdpos  | D_Typecode | F_Ptr | F_Var)
#define D_Kywdsubj	(T_Kywdsubj | D_Typecode | F_Ptr | F_Var)
#define D_Refresh	(T_Refresh  | D_Typecode | F_Ptr)
#define D_Coexpr	(T_Coexpr   | D_Typecode | F_Ptr)
#define D_External	(T_External | D_Typecode | F_Ptr)
#define D_Slots		(T_Slots    | D_Typecode | F_Ptr)
#define D_Kywdwin	(T_Kywdwin  | D_Typecode | F_Ptr | F_Var)
#define D_Kywdstr	(T_Kywdstr  | D_Typecode | F_Ptr | F_Var)
#define D_Kywdevent	(T_Kywdevent| D_Typecode | F_Ptr | F_Var)

#define D_Var		(F_Var | F_Nqual | F_Ptr)
#define D_Typecode	(F_Nqual | F_Typecode)

#define TypeMask	63	/* type mask */
#define OffsetMask	(~(D_Var)) /* offset mask for variables */

/*
 * "In place" dereferencing.
 */
#define Deref(d) if (Var(d)) deref(&d, &d)

/*
 * Construct a substring trapped variable.
 */
#define SubStr(dest,var,len,pos)\
   if ((var)->dword == D_Tvsubs)\
      (dest)->vword.bptr = (union block *)alcsubs(len, (pos) +\
         BlkLoc(*(var))->tvsubs.sspos - 1, &BlkLoc(*(var))->tvsubs.ssvar);\
   else\
      (dest)->vword.bptr = (union block *)alcsubs(len, pos, (var));\
   (dest)->dword = D_Tvsubs;

/*
 * Find debug struct in procedure frame, assuming debugging is enabled.
 *  Note that there is always one descriptor in array even if it is not
 *  being used.
 */
#define PFDebug(pf) ((struct debug *)((char *)(pf).t.d +\
    sizeof(struct descrip) * ((pf).t.num ? (pf).t.num : 1)))

/*
 * Macro for initialized procedure block.
 */
#define B_IProc(n) struct {word title; word blksize; int (*ccode)();\
   word nparam; word ndynam; word nstatic; word fstatic;\
   struct sdescrip quals[n];}

#define ssize    (curstring->size)
#define strbase  (curstring->base)
#define strend   (curstring->end)
#define strfree  (curstring->free)

#define abrsize  (curblock->size)
#define blkbase  (curblock->base)
#define blkend   (curblock->end)
#define blkfree  (curblock->free)

#if COMPILER
   
   #ifdef Graphics
      #define Poll() if (!pollctr--) pollctr = pollevent()
   #else				/* Graphics */
      #define Poll()
   #endif				/* Graphics */
   
#else					/* COMPILER */
   
   /*
    * Definitions for the interpreter.
    */
   
   /*
    * Codes returned by invoke to indicate action.
    */
   #define I_Builtin	201	/* A built-in routine is to be invoked */
   #define I_Fail	202	/* goal-directed evaluation failed */
   #define I_Continue	203	/* Continue execution in the interp loop */
   #define I_Vararg	204	/* A function with a variable number of args */
   
   /*
    * Generator types.
    */
   #define G_Csusp		1
   #define G_Esusp		2
   #define G_Psusp		3
   #define G_Fsusp		4
   #define G_Osusp		5
   
   /*
    * Evaluation stack overflow margin
    */
   #define PerilDelta 100
   
   /*
    * Macro definitions related to descriptors.
    */
   
   /*
    * The following code is operating-system dependent [@rt.01].  Define
    *  PushAval for computers that store longs and pointers differently.
    */
   
   #if PORT
      #define PushAVal(x) PushVal(x)
      Deliberate Syntax Error
   #endif				/* PORT */
   
   #if AMIGA || ARM || ATARI_ST || MACINTOSH || MVS || UNIX || VM || VMS
      #define PushAVal(x) PushVal(x)
   #endif				/* AMIGA || ARM || ATARI_ST ... */
   
   #if MSDOS || OS2
      #if HIGHC_386 || ZTC_386 || INTEL_386 || WATCOM || BORLAND_386 || SCCX_MX
         #define PushAVal(x) PushVal(x)
      #else				/* HIGHC_386 || ZTC_386 || ... */
         static union {
                pointer stkadr;
                word stkint;
            } stkword;
         
         #define PushAVal(x)  {sp++; \
         			stkword.stkadr = (char *)(x); \
         			*sp = stkword.stkint;}
      #endif				/* HIGHC_386 || ZTC_386 || ... */
   #endif				/* MSDOS || OS2 */
   
   /*
    * End of operating-system specific code.
    */
   
   /*
    * Macros for pushing values on the interpreter stack.
    */
   
   /*
    * Push descriptor.
    */
   #define PushDesc(d)	{*++sp = ((d).dword); sp++;*sp =((d).vword.integr);}
   
   /*
    * Push null-valued descriptor.
    */
   #define PushNull	{*++sp = D_Null; sp++; *sp = 0;}
   
   /*
    * Push word.
    */
   #define PushVal(v)	{*++sp = (word)(v);}
   
   /*
    * Macros related to function and operator definition.
    */
   
   /*
    * Procedure block for a function.
    */
   
   #if VMS
      #define FncBlock(f,nargs,deref) \
      	struct b_iproc Cat(B,f) = {\
      	T_Proc,\
      	Vsizeof(struct b_proc),\
      	Cat(Y,f),\
      	nargs,\
      	-1,\
      	deref, 0,\
      	{sizeof(Lit(f))-1,Lit(f)}};
   #else				/* VMS */
      #define FncBlock(f,nargs,deref) \
      	struct b_iproc Cat(B,f) = {\
      	T_Proc,\
      	Vsizeof(struct b_proc),\
      	Cat(Z,f),\
      	nargs,\
      	-1,\
      	deref, 0,\
      	{sizeof(Lit(f))-1,Lit(f)}};
   #endif				/* VMS */
   
   /*
    * Procedure block for an operator.
    */
   #define OpBlock(f,nargs,sname,xtrargs)\
   	struct b_iproc Cat(B,f) = {\
   	T_Proc,\
   	Vsizeof(struct b_proc),\
   	Cat(O,f),\
   	nargs,\
   	-1,\
   	xtrargs,\
   	0,\
   	{sizeof(sname)-1,sname}};
   
   /*
    * Operator declaration.
    */
   #define OpDcl(nm,n,pn) OpBlock(nm,n,pn,0) Cat(O,nm)(cargp) register dptr cargp;
   
   /*
    * Operator declaration with extra working argument.
    */
   #define OpDclE(nm,n,pn) OpBlock(nm,-n,pn,0) Cat(O,nm)(cargp) register dptr cargp;
   
   /*
    * Agent routine declaration.
    */
   #define AgtDcl(nm) Cat(A,nm)(cargp) register dptr cargp;
   
   /*
    * Macros to access Icon arguments in C functions.
    */
   
   /*
    * n-th argument.
    */
   #define Arg(n)	 	(cargp[n])
   
   /*
    * Type field of n-th argument.
    */
   #define ArgType(n)	(cargp[n].dword)
   
   /*
    * Value field of n-th argument.
    */
   #define ArgVal(n)	(cargp[n].vword.integr)
   
   /*
    * Specific arguments.
    */
   #define Arg0	(cargp[0])
   #define Arg1	(cargp[1])
   #define Arg2	(cargp[2])
   #define Arg3	(cargp[3])
   #define Arg4	(cargp[4])
   #define Arg5	(cargp[5])
   #define Arg6	(cargp[6])
   #define Arg7	(cargp[7])
   #define Arg8	(cargp[8])
   
   /*
    * Miscellaneous macro definitions.
    */
   
   #ifdef MultiThread
      #define glbl_argp (curpstate->Glbl_argp)
      #define kywd_err  (curpstate->Kywd_err)
      #define kywd_pos  (curpstate->Kywd_pos)
      #define kywd_prog  (curpstate->Kywd_prog)
      #define kywd_ran  (curpstate->Kywd_ran)
      #define k_eventcode (curpstate->eventcode)
      #define k_eventsource (curpstate->eventsource)
      #define k_eventvalue (curpstate->eventval)
      #define k_subject (curpstate->ksub)
      #define kywd_trc  (curpstate->Kywd_trc)
      #define mainhead (curpstate->Mainhead)
      #define code (curpstate->Code)
      #define ecode (curpstate->Ecode)
      #define records (curpstate->Records)
      #define ftabp (curpstate->Ftabp)
      #ifdef FieldTableCompression
         #define ftabwidth (curpstate->Ftabwidth)
         #define foffwidth (curpstate->Foffwidth)
         #define ftabcp (curpstate->Ftabcp)
         #define ftabsp (curpstate->Ftabsp)
         #define focp (curpstate->Focp)
         #define fosp (curpstate->Fosp)
         #define fo (curpstate->Fo)
         #define bm (curpstate->Bm)
      #endif				/* FieldTableCompression */
      #define fnames (curpstate->Fnames)
      #define efnames (curpstate->Efnames)
      #define globals (curpstate->Globals)
      #define eglobals (curpstate->Eglobals)
      #define gnames (curpstate->Gnames)
      #define egnames (curpstate->Egnames)
      #define statics (curpstate->Statics)
      #define estatics (curpstate->Estatics)
      #define n_globals (curpstate->NGlobals)
      #define n_statics (curpstate->NStatics)
      #define strcons (curpstate->Strcons)
      #define filenms (curpstate->Filenms)
      #define efilenms (curpstate->Efilenms)
      #define ilines (curpstate->Ilines)
      #define elines (curpstate->Elines)
      #define current_line_ptr (curpstate->Current_line_ptr)
      
      #ifdef PosixFns
         #define amperErrno (curpstate->AmperErrno)
      #endif

      #ifdef Graphics
         #define amperX   (curpstate->AmperX)
         #define amperY   (curpstate->AmperY)
         #define amperRow (curpstate->AmperRow)
         #define amperCol (curpstate->AmperCol)
         #define amperInterval (curpstate->AmperInterval)
         #define lastEventWin (curpstate->LastEventWin)
         #define lastEvFWidth (curpstate->LastEvFWidth)
         #define lastEvLeading (curpstate->LastEvLeading)
         #define lastEvAscent (curpstate->LastEvAscent)
         #define kywd_xwin (curpstate->Kywd_xwin)
         #define xmod_control (curpstate->Xmod_Control)
         #define xmod_shift (curpstate->Xmod_Shift)
         #define xmod_meta (curpstate->Xmod_Meta)
      #endif				/* Graphics */
      
      #ifdef EventMon
         #define linenum  (curpstate->Linenum)
         #define column   (curpstate->Column)
         #define lastline (curpstate->Lastline)
         #define lastcol  (curpstate->Lastcol)
      #endif				/* EventMon */
      
      #define coexp_ser (curpstate->Coexp_ser)
      #define list_ser  (curpstate->List_ser)
      #define set_ser   (curpstate->Set_ser)
      #define table_ser (curpstate->Table_ser)
      
      #define curstring (curpstate->stringregion)
      #define curblock  (curpstate->blockregion)
      #define strtotal  (curpstate->stringtotal)
      #define blktotal  (curpstate->blocktotal)
      
      #define coll_tot  (curpstate->colltot)
      #define coll_stat (curpstate->collstat)
      #define coll_str  (curpstate->collstr)
      #define coll_blk  (curpstate->collblk)
      
      #define lastop    (curpstate->Lastop)
      #define lastopnd  (curpstate->Lastopnd)
      
      #define xargp     (curpstate->Xargp)
      #define xnargs    (curpstate->Xnargs)
      
      #define k_current     (curpstate->K_current)
      #define k_errornumber (curpstate->K_errornumber)
      #define k_errortext   (curpstate->K_errortext)
      #define k_errorvalue  (curpstate->K_errorvalue)
      #define have_errval   (curpstate->Have_errval)
      #define t_errornumber (curpstate->T_errornumber)
      #define t_have_val    (curpstate->T_have_val)
      #define t_errorvalue  (curpstate->T_errorvalue)
      
      #define k_main        (curpstate->K_main)
      #define k_errout      (curpstate->K_errout)
      #define k_input       (curpstate->K_input)
      #define k_output      (curpstate->K_output)
      
      #define ENTERPSTATE(p) if (((p)!=NULL)) { curpstate = (p); }
   #endif				/* MultiThread */
   
#endif					/* COMPILER */

/*
 * Constants controlling expression evaluation.
 */
#if COMPILER
   #define A_Resume	-1	/* expression failed: resume a generator */
   #define A_Continue	-2	/* expression returned: continue execution */
   #define A_FallThru	-3      /* body function: fell through end of code */
   #define A_Coact	1	/* co-expression activation */
   #define A_Coret	2	/* co-expression return */
   #define A_Cofail	3	/* co-expression failure */
#else					/* COMPILER */
   #define A_Resume	1	/* routine failed */
   #define A_Pret_uw	2	/* interp unwind for Op_Pret */
   #define A_Unmark_uw	3	/* interp unwind for Op_Unmark */
   #define A_Pfail_uw	4	/* interp unwind for Op_Pfail */
   #define A_Lsusp_uw	5	/* interp unwind for Op_Lsusp */
   #define A_Eret_uw	6	/* interp unwind for Op_Eret */
   #define A_Continue	7	/* routine returned */
   #define A_Coact	8	/* co-expression activated */
   #define A_Coret	9	/* co-expression returned */
   #define A_Cofail	10	/* co-expression failed */
   #ifdef MultiThread
      #define A_MTEvent	11	/* multithread event */
   #endif				/* MultiThread */
   #ifdef PosixFns
      #define	A_Trapret	12	/* Return from stub  */
      #define	A_Trapfail	12	/* Fail from stub  */
   #endif 				/* PosixFns */
#endif					/* COMPILER */

/*
 * Address of word containing cset bit b (c is a struct descrip of type Cset).
 */
#define CsetPtr(b,c)	(BlkLoc(c)->cset.bits + (((b)&0377) >> LogIntBits))

#if MSDOS
   #if (MICROSOFT && defined(M_I86HM)) || (TURBO && defined(__HUGE__))
      #define ptr2word(x) ((uword)((char huge *)x - (char huge *)zptr))
      #define word2ptr(x) ((char huge *)((char huge *)zptr + (uword)x))
   #else				/* MICROSOFT ... */
      #define ptr2word(x) (uword)x
      #define word2ptr(x) ((char *)x)
   #endif				/* MICROSOFT ... */
#endif					/* MSDOS */


#ifdef ISQL                             /* ODBC support */

   /*
    * Icon/ODBC error codes
    */
   #define ODBC_ERR_SZ            19
  
   #define NOT_ODBC_FILE_ERR    1100
   #define FREE_STMT_ERR        1101
   #define DISCONNECT_ERR       1102
   #define FREE_CONNECT_ERR     1103
   #define ALLOC_STMT_ERR       1104
   #define ALLOC_ENV_ERR        1105
   #define ALLOC_CONNECT_ERR    1106
   #define CONNECT_ERR          1107
   #define EXEC_DIRECT_ERR      1108
   #define CLOSE_CURSOR_ERR     1109
   #define COLUMNS_ERR          1110
   #define PRIMARY_KEYS_ERR     1111
   #define NUM_RESULT_COLS_ERR  1112
   #define DESCRIBE_COL_ERR     1113
   #define FETCH_ERR            1114
   #define TABLES_ERR           1115
   #define NO_KEY_DEFINED_ERR   1116
   #define TOO_MANY_KEYS_ERR    1117
   #define KEY_MISSING_ERR      1118

#endif					/* ISQL */
