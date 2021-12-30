import javax.swing.*;

class complex
{
	private double real,imag;
	//constructors
	complex()
	{
		real =0;
		imag = 0;
	}
	complex(double r,double i)
	{
		real =r;
		imag = i;
	}
	//operations
	complex add(complex num)
	{
		complex temp = new complex();
		temp.real = real + num.real;
		temp.imag = imag+num.imag;
		return temp;
	}
	complex multiply(complex num)
	{
		complex temp = new complex();
		temp.real = real*num.real - imag * num.imag;
		temp.imag = real*num.imag + imag*num.real;
		return temp;
	}
	complex pow(int d)
	{
		complex temp = new complex(1,0);
		for (int i=0;i<d;i++)
			temp = temp.multiply(this);
		return temp;
	}
	void set(double r ,double i)
	{
		real = r;
		imag = i;
	}
	public static void main(String []str)
	{
		int N;
		N=Integer.parseInt(JOptionPane.showInputDialog("N = "));
		complex w  = new complex(Math.cos(-2*(22.0/7)/N),Math.sin(-2*(22.0/7.0)/N));
		complex X  =new complex();
		complex[] x=new complex[N];

		for (int p=0;p<N;p++)
			x[p]=new complex();

		for (int l=0;l<N;l++)
			x[l].set(Double.parseDouble(JOptionPane.showInputDialog("Enter x"+l)), 0);

		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++)
				X=X.add(x[j].multiply(w.pow(j*i)));
			if(X.imag >= 0)
				System.out.println(adapt(X.real) + " +"+adapt(X.imag)+"\n");
			else
				System.out.println(adapt(X.real) +adapt(X.imag)+"\n");

			X.real =X.imag=0;
		}
	}
	private static String adapt(double d)
	{
		if(d>0.01 || d<-0.01)
			return d+"";
		else
			return 0+"";
	}
}
