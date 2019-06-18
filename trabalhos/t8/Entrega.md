[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2019a) > Trabalho 8


### Professora: Andrea Charao
### Aluno: Henrique Velho

As referidas parte1 e parte2 deste trabalho foram executadas no GoogleColaboratory com a gpu Tesla T4
Todos os resultados time, foram feitas 10 execuções e calculadas as medias resultantes.

### Parte 1



| Tamanho	    | Quantidade    | Wave.cpp      | Wavecuda1     |
|-------------  |------------   |-----------    |-----------    |
| 1024          | 100           | 5.2816 s      | 0.6245 s      |
| 1024          | 200           | 10.381 s      | 0.6709 s      |
| 2048          | 64            | 13.367 s      | 2.0070 s      |
| 2048          | 128           | 26.381 s      | 2.0891 s      |
| 512           | 32            | 0.4083 s      | 0.2865 s      |
| 512           | 64            | 0.8898 s      | 0.2463 s      |
| 128           | 32            | 0.0278 s      | 0.0197 s      |
| 128           | 64            | 0.0518 s      | 0.0201 s      |
| 1024          | 50            | -      s      | 0.6092 s      |
| 1024          | 600           | -      s      | 1.7834 s      |

Analisando os tempos com o nvprof, pode-se concluir que o tempo do cudaFree aumenta drasticamente e proporcionalmente de acordo com a variação da quantidade de frames,
como podemos ver nos prints das execuções em (link)

As duas ultimas execuções, variando a quantidade de frames 50 - 600 é dedicada para a analise do CudaFree


| Tamanho	    | Quantidade    | CudaFree      |
|-------------  |------------   |-----------    |
| 1024          | 50            | -1.6152ms     |
| 1024          | 600           | -17.915ms     |



Ou seja, uma variação de tempo de 10.92%, sendo que outros como por exemplo o cudaMallocManaged se manteve tecnicamente constante.


### Parte 2


