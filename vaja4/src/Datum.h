#ifndef DATUM_H_
#define DATUM_H_

class Datum {
	private:
		int dan;
		int mesec;
		int leto;
	public:
		Datum();
		Datum(int dan, int mesec, int leto);
		~Datum();
		int getDan() const;
		int getLeto() const;
		int getMesec() const;
		void setDan(int dan);
		void setLeto(int leto);
		void setMesec(int mesec);
};

#endif /* DATUM_H_ */
