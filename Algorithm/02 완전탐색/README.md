`���ȣ��`�� `����Ž��`

### ���ѷ����� ������ �������� ?

> - ���� ��� (base case): ��� �ϳ��� recursion�� ������ �ʴ� ��찡 �����ؾ� �Ѵ�.
> - recursive case : recursion�� �ݺ��ϴٺ��� �ᱹ base case�� �����ؾ� �Ѵ�.

**<��ø �ݺ��� ��ü�ϱ�>**

- ����: n���� ���� �� m���� ���� ��� ������ ã�� �˰���

��ø �ݺ������� ������ �� ������ ��� ȣ���� �ݺ������� �����ϰ� ������ �ڵ带 �ۼ��� �� �ִ�.<br>���� ���ҵ��� ���� **�۾�**�� ������ ���� �Էµ��� �������� ����

> - ���ҵ��� �� ����
> - �� ���� �� ���ҵ��� ����
> - ���ݱ��� �� ���ҵ�

```java
import java.util.ArrayList;

// n : ��ü ������ ��
// picked : ���ݱ��� �� ���ҵ��� ��ȣ
// toPick : �� �� ������ ��
public class recursionEx {

	static void pick(int n, ArrayList<Integer> picked, int toPick) {
        // ������� : �� �� ���Ұ� ���� �� �� ���ҵ��� ���
		if (toPick == 0) {
			System.out.println(picked);
			return;
		}

        // �� �� �ִ� ���� ���� ��ȣ ���
		int smallest = picked.isEmpty() ? 0 : picked.get(picked.size() - 1);
		for (int next = smallest; next < n; next++) {
			picked.add(next);
			pick(n, new ArrayList<Integer>(picked), toPick - 1);
			picked.remove(picked.size() - 1);
		}
	}
	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<Integer>();
		pick(5, arr, 2);
	}
}
```

��� ȣ���� �̿��ϸ� Ư�� ������ �����ϴ� ������ ��� �����ϴ� �ڵ带 ���� �ۼ��� �� �ִ�. <br>
������ `��� ȣ��`�� `���� Ž��`�� ������ �� ���� ������ ����!
