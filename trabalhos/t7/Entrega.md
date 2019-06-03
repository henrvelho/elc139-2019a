[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2019a) > Trabalho 5


### Professora: Andrea Charao
### Aluno: Henrique Velho

As referidas parte1 e parte2 deste trabalho foram executadas no processador corei5 3337u com 5,1GFlops 
Todos os resultados time, foram feitas 10 execuções e calculadas as medias resultantes.

### Parte 1

 Código fornecido [sr_bcast.c](sr_bcast.c)

 Código implementado [MPI_Bcast nativa](part1.c)

 graficos // soon

 **Resultados**

| send/recieve |          | MPI_bcast |          |   |
|--------------|----------|-------|----------|---|
| np           | time     | np    | time     |   |
| 1            | 0.185    | 1     | 0.161 |   |
| 2            | 0.188    | 2     | 0.169 |   |
| 4            | 0.201    | 4     | 0.219 |   |
| 8            | 0.230    | 8     | 0.289 |   |
| 16           | 0.303    | 16    | 0.289 |   |
| 32           | 0.471    | 32    | 0.422 |   |
| 64           | 1.351    | 64    | 1.163 |   |
| 128          | 3.898    | 128   | 3.035 |   |
| 256          | 7.163    | 256   | 6.813 |   |



### Parte 2

