### Dockersѧϰ


- Hello world  
```sh
docker run ubuntu:15.10 /bin/echo "Hello world"
```
- ���н���ʽ������  
����ͨ��docker���������� -i -t����docker���е�����ʵ��"�Ի�"������
```sh
docker run -i -t ubuntu:18.04 /bin/bash
```

-t:����������ָ��һ��α�ն˻��նˡ�  
  
-i:������������ڵı�׼���� (STDIN) ���н�����  

- ��̨ģʽ   
```sh
docker run -d ubuntu:18.04 /bin/sh -c "while true; do echo hello world; sleep 1; done"
```
������Ҫȷ�������������У�����ͨ�� docker ps ���鿴

- ֹͣ����  
```sh
docker stop name
```
- �г������б�  

���ǿ���ʹ�� docker images ���г����������ϵľ���

- REPOSITORY����ʾ����Ĳֿ�Դ 

- TAG������ı�ǩ  

- IMAGE ID������ID  

- CREATED�����񴴽�ʱ��  

- SIZE�������С    

ͬһ�ֿ�Դ�����ж�� TAG����������ֿ�Դ�Ĳ�ͬ���汾����ubuntu�ֿ�Դ���15.10��14.04�ȶ����ͬ�İ汾������ʹ�� REPOSITORY:TAG �����岻ͬ�ľ���


- ��ȡһ���µľ���  
�������ڱ���������ʹ��һ�������ڵľ���ʱ Docker �ͻ��Զ���������������������Ԥ����������������ǿ���ʹ�� docker pull ��������������
```sh
docker pull ubuntu:13.10
```

- ���Ҿ���  

```sh
docker search httpd
```
