## Note
- c++ 컴파일러로 machine code를 생성하는데 반해 자바는 intermediate code (즉, jave byte code)를 생성. 이를 JVM에서 동작. 이러한 JVM을 돌리는데 시간이 소요되고, 따라서 약간의 성능의 저하를 가져온다.   

- 자바는 automatic memory management을 수행한다. 가비지 컬렉터를 수행하는데 시간이 소요됨. 즉, die young이면 문제가 거의 없겠지만, 어떤 변수들은 heap에서 오랫동안 머무는 녀석도 있는데 이를 추적해서 없애야 하는데 시간이 소요되기 때문.

- 최근의 자바 컴파일러가 최적화되어 있어 GC를 많이 필요하지 않는 경우에는 C++보다 빠르기도 한다.

- GC의 params가 수백가지가 되기 때문에 이를 적절히 조절하는 것이 쉽지 않다.


- | C | Java
- | -|-
- | object code | byte code
 |   |byte code를 JVM을 통해 object code로 바꾼 후 머신으로
GC |  | "most objects die young" model인 경우에는 좋다. o/w, JVM will spend a lot of resources traversing the heap.
Larger objects |allows you to have POD structs with no overhead | All objects have a vtable pointer, Larger objects == fewer objects in the cache == slower
Lack of inline objects | objects can be allocated within other objects or on the stack.  This can increase cache locality, and reduce the cost of dynamic memory allocation. | all classes are pointers
https://www.quora.com/In-what-cases-is-Java-slower-than-C-by-a-big-margin

- In my areas of machine learning and high performance computing, where there are a lot of matrix and vector computations, the biggest speed gain from C++ vs. managed language (JVM or .NET) is the ability to write SIMD code using SSE/AVX instructions or CUDA/OpenCL (if you program to run on GPUs).
https://www.quora.com/In-what-cases-is-Java-slower-than-C-by-a-big-margin
