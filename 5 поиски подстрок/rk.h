// Алгоритм Рабина-Карпа
int rksearch (string ins, string ses,int pr)
{
	int M = ses.length();
	int N = ins.length();
    int p = 0;
    int t = 0;
    int h = 1;
    for (int i = 0; i < M-1; i++)
		h = (h*256)%pr;
    for (int i = 0; i < M; i++)
    {
		p = (256*p + ses[i])%pr;
		t = (256*t + ins[i])%pr;
    }
    for (int i = 0; i <= N - M; i++)
    {
		if ( p == t )
        {
			int j;
            for (j = 0; j < M; j++)
            {
                if (ins[i+j] != ses[j])
                    break;
            }
            if (j == M)
            {
				return i%256;
            }
        }        
        if ( i < N-M )
        {
			t = (256*(t - ins[i]*h) + ins[i+M])%pr;
            if (t < 0) 
				t = (t + pr); 
        }
    }
	return -1;
}