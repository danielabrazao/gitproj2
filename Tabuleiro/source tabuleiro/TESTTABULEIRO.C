/***************************************************************************
*  $MCI M�dulo de implementa��o: TAB Tabuleiro de Gam�o
*
*  Arquivo gerado:              TABULEIRO.C
*  Letras identificadoras:		TTAB
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores:	fvc	- Felipe Vieira Cortes
*			tbm - T�ssio Borges de Miranda
*			db  - Daniela Braz�o
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor		  Data     Observa��es
*	  2		  fvc, tbm 	23/set/2015 t�rmino do deselvolvimento
*     1       fvc, tbm	21/set/2015 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo Matriz. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo Matriz:
*
*     =criartabuleiro		<CondRet>		- Chama a fun��o    TAB_tpCondRet TAB_CriarTabuleiro(TAB_tppTabuleiro * pTab, void   ( * ExcluirValor ) ( void * pDado ) ) ;
*	  =destruirtabuleiro	<CondRet>		- Chama a fun��o  TAB_tpCondRet TAB_DestruirTabuleiro( TAB_tppTabuleiro pTab );
*     =moverpeca			<casaOrig> <CasaDest>	<CondRet>	 - Chama a fun��o TAB_tpCondRet TAB_MoverPeca( TAB_tppTabuleiro pTab, int casaOrigem, int casaDestino ) ;
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    "TST_ESPC.H"
#include    "GENERICO.h"
#include    "lerparm.h"

#include	"TABULEIRO.H"

/* Tabela dos nomes dos comandos de teste espec�ficos */
#define     CRIAR_TABULEIRO_CMD			"=criartabuleiro"
#define     DESTRUIR_TABULEIRO_CMD      "=destruirtabuleiro"
#define     MOVER_PECA_CMD				"=moverpeca"

TAB_tppTabuleiro Tab;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static void DestruirValor( void * pValor ) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TTAB Efetuar opera��es de teste espec�ficas para o Modulo Tabuleiro
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     de Tabuleiro de gam�o.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int CondRetObtido   = TAB_CondRetOK ;
      int CondRetEsperada = TAB_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */
      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;
	  char corEsperada	= 'x';

      int  NumLidos = -1 ;
	  int i = 0;
	  int PosicaoReferencia, PosicaoFinal;
	
      /* Testar  Criar Tabuleiro */
         if ( strcmp( ComandoTeste , CRIAR_TABULEIRO_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
									 &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TAB_CriarTabuleiro(&Tab, DestruirValor);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar o tabuleiro." );

         } /* fim ativa: Testar Criar Tabuleiro */

		 /* Testar  Destruir Tabuleiro*/
		 else	if ( strcmp( ComandoTeste , DESTRUIR_TABULEIRO_CMD ) == 0 )
         {

			NumLidos = LER_LerParametros( "i" ,
                              &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = TAB_DestruirTabuleiro(Tab) ;

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao destruir o tabuleiro" );
			
         } /* fim ativa: Testar destruir tabuleiro */

		/* Testar  Tabuleiro Mover Peca*/
		 else	if ( strcmp( ComandoTeste , MOVER_PECA_CMD ) == 0 )
         {

			NumLidos = LER_LerParametros( "iii" ,
                             &PosicaoReferencia,&PosicaoFinal , &CondRetEsperada ) ;
            if ( NumLidos != 3)
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = TAB_MoverPeca(Tab,  PosicaoReferencia, PosicaoFinal ) ;

			return TST_CompararInt(CondRetObtido, CondRetEsperada, "Retorno errado ao mover a peca");

         } /* fim ativa: Testar  Tabuleiro Mover Peca */
      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: Tab Efetuar opera��es de teste espec�ficas para Tabuleiro */

   /***********************************************************************
*
*  $FC Fun��o: TTAB -Destruir valor
*
***********************************************************************/

void DestruirValor( void * pValor )
   {

      free( pValor ) ;

   } /* Fim fun��o: TTAB-Destruir valor */