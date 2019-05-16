[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2019a) > Trabalho 6


### Professora: Andrea Charao
### Aluno: Henrique Velho

### Parte 1

	
[Link código parte 1](https://github.com/henrvelho/elc139-2019a/blob/master/trabalhos/t6/parte1.c)

O código original do problema da multiplicação de matrizes, era resolvido com chamadas de MPI_Send e MPI_Recv, realizando uma análise é possivel realizar o uso de MPI_Bcast e MPI_Scatter e no fim a união do resultado MPI_Gatter
Alguns aspectos importantes:

	MPI_Bcast: Ele envia a matriz B do root processo 0 para todos os outros.
	MPI_Scatter: Faz a divisão da matriz A e envia os dados aos outros processos com o mesmo root(raiz).
	MPI_Gatter: Realiza mesma operação do Scatter só que ao contrário, reune todos os outros processos em um só (root no caso).
	
Segue imagem ilustrativa:

![3](bcast_scatter.png)



### Parte 2

Serguei Gorlatch aborda em seu artigo "Send-Receive Considered Harmful: Myths and Realities of Message Passing" da "Universit¨at M¨unster" faz uma critica ao uso de Send and Receive e classifica como primitivo e incompreensivel, e adota o uso de "collective operations". Um exemplo prático, podemos ver no trabalho 6 da disciplina Programação Paralela, o qual adota primeiramente uso de Send/Receive e posteriormente podemos analisar melhor compreensão do código com o uso de MPI_Bcast e MPI_Scatter. 

Voltando ao artigo de Serguei, ele compara o uso de GOTO com Send/Receive ao qual Dijkstra afirmou que GOTO deixava programas sequencias complexos e inelegiveis e que é possivel escrever qualquer programa sem o uso de GOTO. A não utilização de GOTO é um grande passo para a programação estruturada e a substituição de Send/Receive é de suma importancia para a programação paralela. Serguei aborda alguns desafios para provar os beneficios da operação coletiva como alternatica ao Send/Receive: Simplicidade, Programabilidade, Expressividade, Desempenho, Previsibilidade.

Simplicidade: O mito afirma que Send/Receive são maneiras simples de especificar a comunicação de programas paralelos, porém existem oito tipos diferentes de Send e mais dois tipos diferentes de Receive resultando em 16 combinações possíveis de Send/Receive tornando assim o nível de abstração do código muito alto e menos compreensivel.

Programabilidade: O mito afirma que o design de programas paralelos é tão complicado que provavelmente sempre permanece uma atividade "ad hoc" em vez de um processo sistemático, Serguei afirma que com operações coletivas facilitam transformações de programa de alto nível que pode ser aplicado em um processo sistemático de design de programa.

Expressividade: O mito afirma que as operações coletivas são muito inflexiveis e incapazes de expresssar muitas aplicações importantes, para esse mito, Serguei apresenta várias aplicações que foram implementadas usando somente operações coletivas e sem perda notável de desempenho comparado com Send/Receive.

Desempenho: O mito afirma que programas que usam Send/Receive são naturalmente mais rápidos que suas peçãs usando operações coletivas. Send e Receive podem serem implementados a nivel de hardware, permitindo assim todos os recursos da maquina explorados e portando serem mais rápidos do que operação coletivas, entretanto há fortes evidencias que Send e Receive não oferece vantagens de desempenho em relação as operações coletivas e que oferece implementações ajustadas e eficiente sem alterar as proprias aplicações.

Previsibilidade: O mito afirma que informações de desempenho confiaveis para programas paralelos so podem ser obtidas "posteriores" isto é, executando o programa em uma determinada configuração da maquina. Usar operações coletivas segundo Serguei, podem ter seu impacto calculado e contribuir para uma organização mais correta.


### Referências:

- [MPI: A Message-Passing Interface Standard](https://www.mpi-forum.org/docs/mpi-3.1/mpi31-report.pdf)
- [MPI Scatter, Gather, and Allgather](https://mpitutorial.com/tutorials/mpi-scatter-gather-and-allgather/)
- [MPI Broadcast and Collective Communication](https://mpitutorial.com/tutorials/mpi-broadcast-and-collective-communication/)
