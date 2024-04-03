#pragma once
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define N 500 // Число отрезков для вычисления плотности распределения вероятности 
#define M 100000L // Число экспериментов
//float sl_vel(float a, float b);
float f[N];

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
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(725, 458);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
//help
		float D = 1, a = 0.15, d;
		float k1, k2, ea;
		array<float>^ x = gcnew array<float>(N);
		array<int>^ counts = gcnew array<int>(N);

		k2 = exp(-a);
		k1 = sqrt(D * (1.0 - k2 * k2));

		x[0] = gauss(0, D);
		for (int n = 1; n < N; n++) {
			ea = gauss(0, 1);
			x[n] = k1 * ea + k2 * x[n - 1];
		}

		// Find the minimum and maximum values in the x array
		float minValue = x[0];
		float maxValue = x[0];
		for (int i = 1; i < N; i++) {
			if (x[i] < minValue) {
				minValue = x[i];
			}
			if (x[i] > maxValue) {
				maxValue = x[i];
			}
		}

		d = (maxValue - minValue) / N; // bin width

		// Initialize the counts array to zero
		for (int i = 0; i < N; i++) {
			counts[i] = 0;
		}

		// Generate M samples from the x array and count occurrences within each bin
		for (int m = 0; m < M; m++) {
			float sample = x[(int)(rand() % N)];
			int n = (int)floor((sample - minValue) / d);

			if (n >= 0 && n < N) {
				counts[n]++;
			}
		}

		// Convert counts to probability density
		array<float>^ f = gcnew array<float>(N);
		for (int n = 0; n < N; n++) {
			f[n] = counts[n] / (float)(M * d);
		}

		// Plot the probability density
		for (int n = 0; n < N; n++) {
			chart1->Series[0]->Points->AddXY(minValue + n * d, f[n]);
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
