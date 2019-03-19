[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > T1

TOP500 & me: Comparativo de Arquiteturas Paralelas
--------------------------------------------------

Nome: < preencha seu nome aqui >

| Característica                                            | Computador no TOP500  | Meu computador  |
| --------------------------------------------------------- | --------------------- | --------------- |
| Nome/Título                                               |  331 Lenovo C1040     |  Dell inspiron 14-2620
| Imagem (foto, diagrama, screenshot, etc.)                 |  <img src="http://www.top500.org/static//images/Top500_logo.png" width="48"> |  <img src="https://www.tudoemtecnologia.com/wp-content/uploads/2013/12/Dell-Inspiron-14-2620.jpg" width="48">|
| Classificação de Flynn                                    |                       |      SIMD           | 
| Memória: compartilhada, distribuída ou ambas?             |          Distribuida             |     Compartilhada            |
| Número total de núcleos de processamento                  |        38.400         |        2        |
| Fabricante e modelo do(s) processador(es)                 |Intel Xeon E5-2673v4 20c|Intel i5 3337u  |
| Frequência do(s) processador(es)                          |  2.3GHz               |1.80GHz up to 2.7GHz|
| Memória total                                             |        491.520Gb      |       6gb          |
| Tipo(s) de interconexão entre os núcleos/processadores    |      40G Ethernet     |      -           |
| Desempenho Linpack                                        |        1,123.15 TFlops/s               |  33.1769 GFlops/s      |

### Referências
- Intel. Intel® Core™ i5-3337U Processor .https://ark.intel.com/content/www/us/en/ark/products/72055/intel-core-i5-3337u-processor-3m-cache-up-to-2-70-ghz.html.
- Top500 The List. BC1 - Lenovo C1040, Xeon E5-2673v4 20C 2.3GHz, 40G Ethernet. https://www.top500.org/system/179315.
- Autor (nome de pessoa ou instituição). Título. URL.


- Linkpack utilizado: Linkpack Xtreme by Prime95
(Linpack solves a dense (real*8) system of linear equations (Ax=b), measures
the amount of time it takes to factor and solve the system, converts that
time into a performance rate, and tests the results for accuracy)
