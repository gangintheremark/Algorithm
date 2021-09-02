/*
counting cells in a blob
 - binary 이미지
 - 각 픽셀은 background pixel이거나 image pixel
 - 서로 연결된 image pixel들의 집합을 blob 이라 함
 - 상하좌우 및 대각방향도 연결된 것으로 간주

 입력 : N*N 크기의 2차원 그리드, 하나의 좌표 (x,y)
 출력 : pixel (x,y)가 포함된 blob의 크기, (x,y)가 어디에도 속하지 않는 경우는 0 

 <recursive thinking>
 if the pixel (x,y) is outside the grid
    the result is 0;
 else if pixel (x,y) is not an image pixel or already counted
    the result is 0;
 else
    set the colour of the pixel (x,y) to a red colour;
    the result is 1 plus the number of cells in each piece of the blob that includes a nearest neighbour;
 */

public class CountingCellsBlob {
	private static int BACKGROUND_COLOR = 0;
	private static int IMAGE_COLOR = 1;
	private static int ALREADY_COUNTED =2;
	private static int N=8;
	private static int[][] grid = {
			{1,0,0,0,0,0,0,1},
			{0,1,1,0,0,1,0,0},
			{1,1,0,0,1,0,1,0},
			{0,0,0,0,0,1,0,0},
			{0,1,0,1,0,1,0,0},
			{1,0,0,0,1,0,0,1},
			{0,1,1,0,0,1,1,1},		
	}; 

	public static int countCells(int x,int y) {
		if(x<0 || x>=N||y<0||y>=N)
			return 0;
		else if(grid[x][y] != IMAGE_COLOR)
			return 0;
		else {
			grid[x][y] = ALREADY_COUNTED;
			return 1+ countCells(x-1, y+1) + countCells(x,y+1) + countCells(x+1, y+1)
			        + countCells(x-1, y) + countCells(x+1, y) + countCells(x-1, y-1)
			        + countCells(x, y-1) + countCells(x+1, y-1);
		}
	}
	public static void main(String[] args) {
		printGrid();
		int blobCount = countCells(3,5);
		System.out.println();
		System.out.println("Blobcount : " + blobCount);
		printGrid();
	}
	private static void printGrid() {
		for(int x=0; x<N; x++) {
			System.out.print("[");
			for(int y=0;y<N;y++)
				System.out.print(grid[x][y] + ", ");
			System.out.println("]");
		}
	}
}

