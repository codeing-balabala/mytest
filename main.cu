// #include <stdio.h>
// #include <iostream>
// // #include "book.h"

// // #include "foo.cuh"
// __device__ int add1(int a, int b) { return a + b; }

// __global__ void add(int a, int b, int *c) { *c = add1(a, b); }

// int main(void) {
//   int c;
//   int *dev_c;
//   std::cout << "Hello NVCC" << std::endl;
//   cudaMalloc((void **)&dev_c, sizeof(int));
//   add<<<1, 1>>>(2, 7, dev_c);
//   // add(1, 2, dev_c);
//   cudaMemcpy(&c, dev_c, sizeof(int), cudaMemcpyDeviceToHost);
//   printf("2 + 7 = %d\n", c);

//   cudaFree(dev_c);
//   return 0;
// }

#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <iostream>

using namespace std;

// 二：线程执行代码
__global__ void vector_add(float* vec1, float* vec2, float* vecres, int length,
                           int* idx) {
  int tid = threadIdx.y * blockDim.x +
            threadIdx.x;  // 使用了threadIdx.x, threadIdx.x, blockDim.x
  *idx = tid;
  if (tid < length) {
    vecres[tid] = vec1[tid] + vec2[tid];
  }
}

int main() {
  const int length = 16;                  // 数组长度为16
  float a[length], b[length], c[length];  // host中的数组
  for (int i = 0; i < length; i++) {      // 初始赋值
    a[i] = b[i] = i;
  }
  float *a_device, *b_device, *c_device;  // device中的数组
  int* idx;
  int tid;

  cudaMalloc((void**)&a_device, length * sizeof(float));  // 分配内存
  cudaMalloc((void**)&b_device, length * sizeof(float));
  cudaMalloc((void**)&c_device, length * sizeof(float));
  cudaMalloc((void**)&idx, sizeof(int));

  cudaMemcpy(a_device, a, length * sizeof(float),
             cudaMemcpyHostToDevice);  // 将host数组的值拷贝给device数组
  cudaMemcpy(b_device, b, length * sizeof(float), cudaMemcpyHostToDevice);

  // 一：参数配置
  dim3 grid(1, 1, 1), block(length, 2, 1);  // 设置参数
  vector_add<<<grid, block>>>(a_device, b_device, c_device, length,
                              idx);  // 启动kernel

  cudaMemcpy(c, c_device, length * sizeof(float),
             cudaMemcpyDeviceToHost);  // 将结果拷贝到host
  cudaMemcpy(&tid, idx, sizeof(int),
             cudaMemcpyDeviceToHost);  // 将结果拷贝到host

  cout << "tid:" << tid << " \n";

  for (int i = 0; i < length; i++) {  // 打印出来方便观察
    cout << c[i] << " ";
  }
  cout << endl;

  system("pause");
  return 0;
}
