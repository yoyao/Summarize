


   
/*
�������ӽṹ���ܶ������Ĵ𰸣�����ģ�����ɣ����������ص���������ͬ�����ʵĶ��ǣ����б߽��޶���������ѭ��������������������������������ⲻ����Ӱ��),����¼����¼�������״̬����ͨ����һ�������Ķ�ά���飩�ܼ��ټ���Ĵ���������Ч�ʡ�
��������������ö�̬�滮
*/








/*
�����ڵ�1С�ھٵ����ӣ�S1={1,3,4,5,6,7,7,8}��S2={3,5,7,4,8,6,7,8,2}�����������ͼ��˵��
����S1�����һ��Ԫ�� �� S2�����һ��Ԫ����ȣ���ôS1��S2��LCS�͵��� {S1��ȥ���һ��Ԫ��} �� {S2��ȥ���һ��Ԫ��} �� LCS  �ټ��� S1��S2��ȵ����һ��Ԫ�ء�
����S1�����һ��Ԫ�� �� S2�����һ��Ԫ�ز��ȣ������Ӿ��������������������ôS1��S2��LCS�͵��� �� {S1��ȥ���һ��Ԫ��} �� S2 ��LCS�� {S2��ȥ���һ��Ԫ��} �� S1 ��LCS �е������Ǹ����С�
*/

/**********
//�ص����������������仰����ʵ����ܼ� ���Ƕ������仰��ӳ�䡣 ���������Ĺؼ����������Ǹ���ʽ����ʵÿ���ַ�����һ���ַ��ıȽϿ�����Ϊ�Ǵ�0��ʼ���Ƚ��ַ��ĳ��ȵ��ַ� ����һ���ַ���ÿ���������  �ó���������С���Ϊ�Ǵӵ�һ���ַ���ʼ�ģ������൱�ڴ��㿪ʼ��
 1.�����������ĳ��λ�ó�����ȵ��ַ�������˵���������ַ���������е�һԱ��ͬʱҲ�������ַ�����ֹ���˵ĵ�λ����������е����һλ��Ӧ��������λ��������ǡ�Ӧ���ڴ�λ����Ϊ1����λ�õ����Ͻ��������ַ������Լ�ȥһ���ַ����ȵ��������λ�á���������Ǽ���һ�𣬼ӵ���������Ǽ�¼��������еĳ��ȡ����Լ��ϴ�λ����ȣ���������������еĳ���Ҫ+1��

 2.�����������ĳ��λ�õ��ַ�����,����˵��������ֹ���˵��ִ���������г����ڸ��Լ�1��λ���ϡ���1��֪���ڸ����Ķ�ά�����ϵ�λ�÷ֱ�Ϊ[i-1][j]����[i][j-1]�����Ե�ǰλ��������Ҫ�����½�������ǰλ�õ�������г��ȣ�ѡ�����������е����ı��棩�����統ǰλ�õ�Y�᲻��X���������ȵ��ַ� ��Ҳ���� ��Ϊλ�ô��ˡ����������С�

 3.ȫ�������Ժ����һ��λ�ñ����һ���������ַ�����������еĵĳ��ȡ�����������������Կ�֪�������ά����ĵ����һ��λ�õĵ����Ͻ�X,Y�����λ�õ������ַ���ȣ������ĳ��Ⱦ������ϽǼ�1��ĳ��ȣ���Ȼ��+1�����ģ�����˵����ַ�Ҳ��������е�һԱ����¼������������Ͻǲ��ȣ��ǾͿ�[j]��[i][j-1]˭��˭����Ǵ�˭�Ǽ̳й����ģ���¼���λ�õ��ַ�,Ȼ���������ơ�ֱ����ά������X,Y��ֵ����0����ô���������ж��ˡ�����ѭ�������Ǵ�ʱ���ַ�������ģ���Ҫ������
**********/

/*
  int *p = new int(5);
  //new ����һ��5��int��С������
  int *p_p = new Person(4);//�����ڸ�Person��Ĺ��캯�����Ρ�
   int *p_p = new Person[12];//����newһ��12��Person�����顣
   //�ǹؼ���������newʱ��С���Ŵ���˵��������������С�����Ǵ��������촫��
   */