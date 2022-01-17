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

- ���� : [���۰���](https://algospot.com/judge/problem/read/BOGGLE)

5x5 ũ���� ���ĺ� ���ڿ��� �����¿�/�밢������ ������ ĭ���� ���ڸ� �̾ �ܾ ã�Ƴ��� ���̴�. <br><br>
`���� Ž��`�� �̿���, �ܾ ã�Ƴ� ������ ��� ������ ĭ�� �ϳ��� �õ��� ���� ���̴�. ���� �� ĭ������ �ܾ ã�� �� ������ �����̰�, ��� ĭ�� �����ϴ��� ���� ���ٸ� ����. <br> <br>
������ ���� ������ �Լ��� �ۼ��Ѵ�.
<br>
hasWord(y,x,word) = ���� �������� (y,x)���� �����ϴ� �ܾ� word�� ���� ���� ��ȯ

> ���� ���
>
> - ��ġ (y,x)�� ��ġ���� ����� ��� �׻� false
> - ��ġ (y,x)�� �ִ� ���ڰ� ���ϴ� �ܾ��� ù ���ڰ� �ƴ� ��� �׻� false
> - (1�� ��쿡 �ش����� ���� ��)���ϴ� �ܾ �� ������ ��� �׻� true

```java
	static boolean hasWord(int x, int y, String word) {
		if (!inRange(x, y)) // ���� ���̸� false
			return false;
		if (board[x][y] != word.charAt(0)) // ��ġ (x,y)�� �ִ� ���ڰ� word�� ù ���ڰ� �ƴϸ� false
			return false;
		if (word.length() == 1) // ���ϴ� �ܾ �� ������ ��� true
			return true;

		// 8 ĭ �˻�
		for (int i = 0; i < 8; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (hasWord(nextX, nextY, word.substring(1)))
				return true;
		}
		return false;
	}

```

`���� Ž��` ������

1. ���� Ž���� �����ϴ� ��� ���� �ϳ��� �˻��Ͽ� �ɸ��� �ð��� ������ ���� ���� ��Ȯ�� ���.
2. ������ ��� ���� �ĺ��� ����� ������ ����
3. ���� �ϳ��� ������ ������ ���� �Ϻθ� �����, ������ ���� ��� ȣ���� ���� �ϼ�
