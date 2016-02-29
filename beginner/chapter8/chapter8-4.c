#include <stdio.h>
#include <math.h>

enum seasons { Spring, Summer, Autumn, Winter };

int main()
{
	int ans;
	printf("ans = "); scanf("%d", &ans);
	switch(ans) {
	case Spring: 
		printf("暖かくなってきたなぁ\n");
		break;
	case Summer:
		printf("気温ぬるい\n");
		break;
	case Autumn:
		printf("唯一の楽しみ\n");
		break;
	case Winter:
		printf("もう冬かぁ\n");
		break;
	default:
		printf("馬鹿め!\n");
		break;
	}
	return 0;
}
