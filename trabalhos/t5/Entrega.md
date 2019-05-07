[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2019a) > Trabalho 5


### Professora: Andrea Charao
### Aluno: Henrique Velho

### Parte 1

 soon


### Parte 2

Link programa pipeline: [PIPELINE](pipeline_certo.c)


### Parte 3

Link programa errado: [MPI ERRADO 1](mpi_errado1.c)

Link programa certo: [MPI CERTO 1](mpi_certo1.c)
O problema do programa mpi_errado1.c eh o valor passado na variavel tag, gerando assim valores diferentes em MPI_Send e MPI_Recv e nao feita a comunicação dos processos.

-----------------------------------------------------

Link programa errado: [MPI ERRADO 2](mpi_errado2.c)

Link programa certo: [MPI CERTO 2](mpi_certo2.c)
O programa mpi_errado2.c não está usando a finalização do mpi, feito a inserção do MPI_Finalize() em mpi_certo2.c

