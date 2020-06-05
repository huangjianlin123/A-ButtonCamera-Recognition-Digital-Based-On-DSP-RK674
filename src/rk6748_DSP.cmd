/* =========================================================================*
 * RK6748_DSP.cmd - Linker Command File for Linking tms320c6748 DSP Programs	*
 * 																			*
 * These linker options are for command line linking only. For IDE linking, *
 * you should set your linker options in Project Properties.				*
 * 		-c					Link Using C Conventions						*
 *		-stack 	0x1000		Software Stack Size								*
 *		-heap	0x1000		Heap Area Size									*
 * =========================================================================*/
-stack 0x100000

-heap  0x01000000
// -heap 0x1000
//-e fix_start
/* =========================================================================*
 * 						Specify the System Memory Map						*
 * =========================================================================*/
MEMORY
{
	L2R:    o = 0x00700000      l = 0x00100000
	L2:		o = 0x00800000		l = 0x00040000     //1*10e18   256k
	share:	o = 0x80000000		l = 0x00020000     //128k
	L1P:	o = 0x00E00000		l = 0x00008000     //  10e15   32k
	L1D:	o = 0x00F00000		l = 0x00008000  // 32k
	dsp_ddrii:  o = 0xc2000000  l = 0x1E000000 //400M
}

/* =========================================================================*
 * 				Specify the Sections Allocation into Memory					*
 * =========================================================================*/
SECTIONS
{
	.cinit		>		dsp_ddrii				/* Initialization Tables			*/
	.pinit		>		dsp_ddrii				/* C++ Constructor Tables			*/
	.const		>		dsp_ddrii				/* Constant Data					*/
	.switch		>		dsp_ddrii				/* Jump Tables						*/
	.text:_c_int00 > 0xc2000000 
	.text		>		dsp_ddrii				/* Executable Code					*/

     .my_sect: {}  >    dsp_ddrii
	
	.bss		>		dsp_ddrii				/* Global & Static Variables 		*/
	.far		>		dsp_ddrii				/* Far Global & Static Variables	*/
	.stack		>		dsp_ddrii				/* Software System Stack			*/
	.sysmem		>		dsp_ddrii				/* Dynamic Memory Allocation Area 	*/
	
	.cio		>		dsp_ddrii				/* C I/O Buffer						*/
	.vecs		>		dsp_ddrii				/* Interrupt Vectors				*/
}
