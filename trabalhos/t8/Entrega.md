[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2019a) > Trabalho 8


### Professora: Andrea Charao
### Aluno: Henrique Velho

As referidas parte1 e parte2 deste trabalho foram executadas no GoogleColaboratory com a gpu Tesla T4
Todos os resultados time, foram feitas 10 execuções e calculadas as medias resultantes.

### Parte 1

Código implementado [wavecuda1.cu](wavecuda1.cu)

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
como podemos ver nos prints das execuções em [prints](https://github.com/henrvelho/elc139-2019a/tree/master/trabalhos/t8/prints)

As duas ultimas execuções, variando a quantidade de frames 50 - 600 é dedicada para a analise do CudaFree


| Tamanho	    | Quantidade    | CudaFree      |
|-------------  |------------   |-----------    |
| 1024          | 50            | -1.6152ms     |
| 1024          | 600           | -17.915ms     |


Ou seja, uma variação de tempo de 10.92%, sendo que outros como por exemplo o cudaMallocManaged se manteve tecnicamente constante.

Tabela calculo do Speedup:

| Tamanho	    | Quantidade    | SpeedUp       |
|-------------  |------------   |-----------    |
| 1024          | 100           | 8.4573        |
| 1024          | 200           | 15.473        |
| 2048          | 64            | 6.6601        |
| 2048          | 128           | 12.627        |
| 512           | 32            | 1.4251        |
| 512           | 64            | 3.6126        |
| 128           | 32            | 1.4111        |
| 128           | 64            | 2.5777        |




### Parte 2

Código implementado [wavecuda2.cu](wavecuda2.cu)

Para a otimização do código, foi utilizado a chamada #pragma unroll, que segundo pesquisas, abre um branch com até 100 threads e que permite o compilador ter um melhor gerenciamento das váriaveis,
que no nosso caso é row e col.
Segue tabela com os tempos obtidos:


| Tamanho	    | Quantidade    | Wavecuda2     | Wavecuda1     |
|-------------  |------------   |-----------    |-----------    |
| 1024          | 100           | 0.6138 s      | 0.6245 s      |
| 1024          | 200           | 0.6376 s      | 0.6709 s      |
| 2048          | 64            | 2.0458 s      | 2.0070 s      |
| 2048          | 128           | 2.0441 s      | 2.0891 s      |
| 512           | 32            | 0.2763 s      | 0.2865 s      |
| 512           | 64            | 0.2545 s      | 0.2463 s      |
| 128           | 32            | 0.0191 s      | 0.0197 s      |
| 128           | 64            | 0.0197 s      | 0.0201 s      |
| 1024          | 50            | 0.6069 s      | 0.6092 s      |
| 1024          | 600           | 1.7578 s      | 1.7834 s      |


### Bibliografia

- Programming Guide :: CUDA Toolkit Documentation. https://docs.nvidia.com/cuda/cuda-c-programming-guide/
- Fundamental Optimizations in CUDA. http://developer.download.nvidia.com/GTC/PDF/1083_Wang.pdf
- Techniques Optimization CUDA. http://www.cs.virginia.edu/~mwb7w/cuda_support/optimization_techniques.html
- CUDA Best Practices Guide NVIDIA. https://docs.nvidia.com/cuda/cuda-c-best-practices-guide/index.html#optimizing-cuda-applications


