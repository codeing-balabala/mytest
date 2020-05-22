#include <iostream>
/*
void test_ref(void) {
    8a60:	55                   	push   %rbp
    8a61:	48 89 e5             	mov    %rsp,%rbp
    8a64:	48 83 ec 30          	sub    $0x30,%rsp
    8a68:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    8a6f:	00 00 
    8a71:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    8a75:	31 c0                	xor    %eax,%eax
  int value = 100;
    8a77:	c7 45 d8 64 00 00 00 	movl   $0x64,-0x28(%rbp)
  int &value_ref = value;
    8a7e:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
    8a82:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  int *value_ptr = &value;
    8a86:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
    8a8a:	48 89 45 e0          	mov    %rax,-0x20(%rbp)

  // 通过objdump -S -d 反汇编得到 value_ptr 和 value 的地址差 0x08, 用value_ptr - 0x08得到value的地址
  long a = reinterpret_cast<long>(&value_ptr) - 0x08;
    8a8e:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    8a92:	48 83 e8 08          	sub    $0x8,%rax
    8a96:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  // 通过强转把 value的值取出
  int b = *reinterpret_cast<int *>(a);
    8a9a:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    8a9e:	8b 00                	mov    (%rax),%eax
    8aa0:	89 45 dc             	mov    %eax,-0x24(%rbp)
  std::cout << "b:" << b << std::endl;
    8aa3:	48 8d 35 0a 3f 00 00 	lea    0x3f0a(%rip),%rsi        # c9b4 <_ZL9BUFF_SIZE+0x4>
    8aaa:	48 8d 3d 6f 75 20 00 	lea    0x20756f(%rip),%rdi        # 210020 <_ZSt4cout@@GLIBCXX_3.4>
    8ab1:	e8 fa fc ff ff       	callq  87b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    8ab6:	48 89 c2             	mov    %rax,%rdx
    8ab9:	8b 45 dc             	mov    -0x24(%rbp),%eax
    8abc:	89 c6                	mov    %eax,%esi
    8abe:	48 89 d7             	mov    %rdx,%rdi
    8ac1:	e8 aa fd ff ff       	callq  8870 <_ZNSolsEi@plt>
    8ac6:	48 89 c2             	mov    %rax,%rdx
    8ac9:	48 8b 05 f0 74 20 00 	mov    0x2074f0(%rip),%rax        # 20ffc0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    8ad0:	48 89 c6             	mov    %rax,%rsi
    8ad3:	48 89 d7             	mov    %rdx,%rdi
    8ad6:	e8 f5 fc ff ff       	callq  87d0 <_ZNSolsEPFRSoS_E@plt>

  // 通过objdump -S -d 反汇编得到 value_ref 和 value_ptr 的地址差 0x08, 用value_ptr + 0x08得到value_ref的地址
  a = reinterpret_cast<long>(&value_ptr) + 0x08;
    8adb:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    8adf:	48 83 c0 08          	add    $0x8,%rax
    8ae3:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  // 通过强转把 value_ref 的值取出，得到value的地址
  a = *reinterpret_cast<long *>(a);
    8ae7:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    8aeb:	48 8b 00             	mov    (%rax),%rax
    8aee:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  std::cout << reinterpret_cast<long *>(a) << std::endl;
    8af2:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    8af6:	48 89 c6             	mov    %rax,%rsi
    8af9:	48 8d 3d 20 75 20 00 	lea    0x207520(%rip),%rdi        # 210020 <_ZSt4cout@@GLIBCXX_3.4>
    8b00:	e8 5b fc ff ff       	callq  8760 <_ZNSolsEPKv@plt>
    8b05:	48 89 c2             	mov    %rax,%rdx
    8b08:	48 8b 05 b1 74 20 00 	mov    0x2074b1(%rip),%rax        # 20ffc0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    8b0f:	48 89 c6             	mov    %rax,%rsi
    8b12:	48 89 d7             	mov    %rdx,%rdi
    8b15:	e8 b6 fc ff ff       	callq  87d0 <_ZNSolsEPFRSoS_E@plt>

  // 通过强转把 value_ref 的值取出，得到value的地址
  b = *reinterpret_cast<int *>(a);
    8b1a:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    8b1e:	8b 00                	mov    (%rax),%eax
    8b20:	89 45 dc             	mov    %eax,-0x24(%rbp)
  std::cout << "b:" << b << std::endl;
    8b23:	48 8d 35 8a 3e 00 00 	lea    0x3e8a(%rip),%rsi        # c9b4 <_ZL9BUFF_SIZE+0x4>
    8b2a:	48 8d 3d ef 74 20 00 	lea    0x2074ef(%rip),%rdi        # 210020 <_ZSt4cout@@GLIBCXX_3.4>
    8b31:	e8 7a fc ff ff       	callq  87b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    8b36:	48 89 c2             	mov    %rax,%rdx
    8b39:	8b 45 dc             	mov    -0x24(%rbp),%eax
    8b3c:	89 c6                	mov    %eax,%esi
    8b3e:	48 89 d7             	mov    %rdx,%rdi
    8b41:	e8 2a fd ff ff       	callq  8870 <_ZNSolsEi@plt>
    8b46:	48 89 c2             	mov    %rax,%rdx
    8b49:	48 8b 05 70 74 20 00 	mov    0x207470(%rip),%rax        # 20ffc0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    8b50:	48 89 c6             	mov    %rax,%rsi
    8b53:	48 89 d7             	mov    %rdx,%rdi
    8b56:	e8 75 fc ff ff       	callq  87d0 <_ZNSolsEPFRSoS_E@plt>

  std::cout << "&value:" << &value << std::endl;
    8b5b:	48 8d 35 55 3e 00 00 	lea    0x3e55(%rip),%rsi        # c9b7 <_ZL9BUFF_SIZE+0x7>
    8b62:	48 8d 3d b7 74 20 00 	lea    0x2074b7(%rip),%rdi        # 210020 <_ZSt4cout@@GLIBCXX_3.4>
    8b69:	e8 42 fc ff ff       	callq  87b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    8b6e:	48 89 c2             	mov    %rax,%rdx
    8b71:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
    8b75:	48 89 c6             	mov    %rax,%rsi
    8b78:	48 89 d7             	mov    %rdx,%rdi
    8b7b:	e8 e0 fb ff ff       	callq  8760 <_ZNSolsEPKv@plt>
    8b80:	48 89 c2             	mov    %rax,%rdx
    8b83:	48 8b 05 36 74 20 00 	mov    0x207436(%rip),%rax        # 20ffc0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    8b8a:	48 89 c6             	mov    %rax,%rsi
    8b8d:	48 89 d7             	mov    %rdx,%rdi
    8b90:	e8 3b fc ff ff       	callq  87d0 <_ZNSolsEPFRSoS_E@plt>
  std::cout << "&value_ref:" << &value_ref << std::endl;
    8b95:	48 8d 35 23 3e 00 00 	lea    0x3e23(%rip),%rsi        # c9bf <_ZL9BUFF_SIZE+0xf>
    8b9c:	48 8d 3d 7d 74 20 00 	lea    0x20747d(%rip),%rdi        # 210020 <_ZSt4cout@@GLIBCXX_3.4>
    8ba3:	e8 08 fc ff ff       	callq  87b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    8ba8:	48 89 c2             	mov    %rax,%rdx
    8bab:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    8baf:	48 89 c6             	mov    %rax,%rsi
    8bb2:	48 89 d7             	mov    %rdx,%rdi
    8bb5:	e8 a6 fb ff ff       	callq  8760 <_ZNSolsEPKv@plt>
    8bba:	48 89 c2             	mov    %rax,%rdx
    8bbd:	48 8b 05 fc 73 20 00 	mov    0x2073fc(%rip),%rax        # 20ffc0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    8bc4:	48 89 c6             	mov    %rax,%rsi
    8bc7:	48 89 d7             	mov    %rdx,%rdi
    8bca:	e8 01 fc ff ff       	callq  87d0 <_ZNSolsEPFRSoS_E@plt>
  std::cout << "&value_ptr:" << &value_ptr << std::endl;
    8bcf:	48 8d 35 f5 3d 00 00 	lea    0x3df5(%rip),%rsi        # c9cb <_ZL9BUFF_SIZE+0x1b>
    8bd6:	48 8d 3d 43 74 20 00 	lea    0x207443(%rip),%rdi        # 210020 <_ZSt4cout@@GLIBCXX_3.4>
    8bdd:	e8 ce fb ff ff       	callq  87b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    8be2:	48 89 c2             	mov    %rax,%rdx
    8be5:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    8be9:	48 89 c6             	mov    %rax,%rsi
    8bec:	48 89 d7             	mov    %rdx,%rdi
    8bef:	e8 6c fb ff ff       	callq  8760 <_ZNSolsEPKv@plt>
    8bf4:	48 89 c2             	mov    %rax,%rdx
    8bf7:	48 8b 05 c2 73 20 00 	mov    0x2073c2(%rip),%rax        # 20ffc0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    8bfe:	48 89 c6             	mov    %rax,%rsi
    8c01:	48 89 d7             	mov    %rdx,%rdi
    8c04:	e8 c7 fb ff ff       	callq  87d0 <_ZNSolsEPFRSoS_E@plt>
  std::cout << "value_ptr:" << value_ptr << std::endl;
    8c09:	48 8d 35 c7 3d 00 00 	lea    0x3dc7(%rip),%rsi        # c9d7 <_ZL9BUFF_SIZE+0x27>
    8c10:	48 8d 3d 09 74 20 00 	lea    0x207409(%rip),%rdi        # 210020 <_ZSt4cout@@GLIBCXX_3.4>
    8c17:	e8 94 fb ff ff       	callq  87b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    8c1c:	48 89 c2             	mov    %rax,%rdx
    8c1f:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    8c23:	48 89 c6             	mov    %rax,%rsi
    8c26:	48 89 d7             	mov    %rdx,%rdi
    8c29:	e8 32 fb ff ff       	callq  8760 <_ZNSolsEPKv@plt>
    8c2e:	48 89 c2             	mov    %rax,%rdx
    8c31:	48 8b 05 88 73 20 00 	mov    0x207388(%rip),%rax        # 20ffc0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    8c38:	48 89 c6             	mov    %rax,%rsi
    8c3b:	48 89 d7             	mov    %rdx,%rdi
    8c3e:	e8 8d fb ff ff       	callq  87d0 <_ZNSolsEPFRSoS_E@plt>
  std::cout << "value:" << value << std::endl;
    8c43:	48 8d 35 98 3d 00 00 	lea    0x3d98(%rip),%rsi        # c9e2 <_ZL9BUFF_SIZE+0x32>
    8c4a:	48 8d 3d cf 73 20 00 	lea    0x2073cf(%rip),%rdi        # 210020 <_ZSt4cout@@GLIBCXX_3.4>
    8c51:	e8 5a fb ff ff       	callq  87b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    8c56:	48 89 c2             	mov    %rax,%rdx
    8c59:	8b 45 d8             	mov    -0x28(%rbp),%eax
    8c5c:	89 c6                	mov    %eax,%esi
    8c5e:	48 89 d7             	mov    %rdx,%rdi
    8c61:	e8 0a fc ff ff       	callq  8870 <_ZNSolsEi@plt>
    8c66:	48 89 c2             	mov    %rax,%rdx
    8c69:	48 8b 05 50 73 20 00 	mov    0x207350(%rip),%rax        # 20ffc0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    8c70:	48 89 c6             	mov    %rax,%rsi
    8c73:	48 89 d7             	mov    %rdx,%rdi
    8c76:	e8 55 fb ff ff       	callq  87d0 <_ZNSolsEPFRSoS_E@plt>
  std::cout << "value_ref:" << value_ref << std::endl;
    8c7b:	48 8d 35 67 3d 00 00 	lea    0x3d67(%rip),%rsi        # c9e9 <_ZL9BUFF_SIZE+0x39>
    8c82:	48 8d 3d 97 73 20 00 	lea    0x207397(%rip),%rdi        # 210020 <_ZSt4cout@@GLIBCXX_3.4>
    8c89:	e8 22 fb ff ff       	callq  87b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    8c8e:	48 89 c2             	mov    %rax,%rdx
    8c91:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    8c95:	8b 00                	mov    (%rax),%eax
    8c97:	89 c6                	mov    %eax,%esi
    8c99:	48 89 d7             	mov    %rdx,%rdi
    8c9c:	e8 cf fb ff ff       	callq  8870 <_ZNSolsEi@plt>
    8ca1:	48 89 c2             	mov    %rax,%rdx
    8ca4:	48 8b 05 15 73 20 00 	mov    0x207315(%rip),%rax        # 20ffc0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    8cab:	48 89 c6             	mov    %rax,%rsi
    8cae:	48 89 d7             	mov    %rdx,%rdi
    8cb1:	e8 1a fb ff ff       	callq  87d0 <_ZNSolsEPFRSoS_E@plt>
}

hello world!
b:100
0x7ffc8b5b0fe8
b:100
&value:0x7ffc8b5b0fe8
&value_ref:0x7ffc8b5b0fe8
&value_ptr:0x7ffc8b5b0ff0
value_ptr:0x7ffc8b5b0fe8
value:100
value_ref:100

结论：在linux gcc 环境下引用的底层实现和指针是一样的
*/
void test_ref(void) {
  int value = 100;
  int &value_ref = value;
  int *value_ptr = &value;

  // objdump -S -d 反汇编得到 value_ptr 和 value 的地址差 0x08, 用value_ptr - 0x08得到value的地址
  long a = reinterpret_cast<long>(&value_ptr) - 0x08;
  // 把 value 值取出
  int b = *reinterpret_cast<int *>(a);
  std::cout << "b:" << b << std::endl;

  // objdump -S -d 反汇编得到 value_ref 和 value_ptr 的地址差 0x08, 用value_ptr + 0x08得到value_ref的地址
  a = reinterpret_cast<long>(&value_ptr) + 0x08;
  // 取出value_ref值，得到 value 的地址
  a = *reinterpret_cast<long *>(a);
  std::cout << reinterpret_cast<long *>(a) << std::endl;
  // 取出 value 值
  b = *reinterpret_cast<int *>(a);
  std::cout << "b:" << b << std::endl;

  std::cout << "&value:" << &value << std::endl;
  std::cout << "&value_ref:" << &value_ref << std::endl;
  std::cout << "&value_ptr:" << &value_ptr << std::endl;
  std::cout << "value_ptr:" << value_ptr << std::endl;
  std::cout << "value:" << value << std::endl;
  std::cout << "value_ref:" << value_ref << std::endl;
}

int main(void) {
  std::cout << "hello world!" << std::endl;

  test_ref();

  return 0;
}