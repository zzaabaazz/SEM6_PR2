#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define N 3000 // Число отрезков для вычисления плотности распределения вероятности 
#define M 100000L // Число экспериментов
//float sl_vel(float a, float b);


namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(29, 2);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(658, 353);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(612, 408);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(72, 377);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(181, 20);
			this->textBox1->TabIndex = 2;
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(693, 2);
			this->chart2->Name = L"chart2";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chart2->Series->Add(series2);
			this->chart2->Size = System::Drawing::Size(658, 353);
			this->chart2->TabIndex = 3;
			this->chart2->Text = L"chart2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1364, 458);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
//help
		double D = 1, a = 0.1;
		array<double>^ x = gcnew array<double>(N);
		array<double>^ ex = gcnew array<double>(N);
		array<double>^ r = gcnew array<double>(500); // массив для оценки корреляционной функции
		int N_realiz;// длительность реализации стационарного 
                     // фрагмента получившегося случайного процесса
		/*___*/
		array<double>^ c = gcnew array<double>(500);
		double aa;
		int n, P, m, k;
		for (n = 0; n < N; n++) {
			ex[n] = gauss(0, 1);
		}
			P = 2. / a;
			for (k = 0; k <= P; k++)
			{
				if (k != 0)
					c[k] = sqrt(D) / sqrt(M_PI * a) * sin(a * k) / k;
				else c[k] = sqrt(D) / sqrt(M_PI * a) * a;
			}
			for (n = 0; n < N; n++)
			{
				x[n] = 0.0;
				for (k = -P; k <= P; k++)
				{
					if (k < 0) aa = c[-k];
					else aa = c[k];

					if (((n - k) >= 0) && ((n - k) < N))
						x[n] = aa * ex[n - k] + x[n];
				}
			}
			for (n = 0; n < (N - 2 * P); n++)
				x[n] = x[n + P];
			N_realiz = N - 2 * P;
			for (m = 0; m < 500; m++)
			{
				r[m] = 0.0;
				for (n = 0; n < (N_realiz - m - 1); n++)
					r[m] = r[m] + 1. / (N_realiz - m) * x[n] * x[n + m];
				chart2->Series[0]->Points->AddXY(m, r[m]);
			}

		// Plot the probability density
		for (int n = 0; n < N; n++) {
			chart1->Series[0]->Points->AddXY(n, x[n]);
			
		}
	}

		   float gauss(float mu, float sigma) {
			   static float spare;
			   static bool hasSpare = false;

			   float ran;

			   if (hasSpare) {
				   hasSpare = false;
				   return spare * sigma + mu;
			   }

			   float u, v, s;
			   do {
				   u = 2.0 * (float)rand() / RAND_MAX - 1.0;
				   v = 2.0 * (float)rand() / RAND_MAX - 1.0;
				   s = u * u + v * v;
			   } while (s >= 1.0 || s == 0.0);

			   float fac = sqrt(-2.0 * log(s) / s);
			   spare = v * fac;
			   hasSpare = true;
			   ran = u * fac;

			   return ran * sigma + mu;
		   }
	};
}
