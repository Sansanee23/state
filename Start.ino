const int START = 0; //กำลังรอแตะบัตร
const int WAIT_FOR_CARD = 1; //ดึงข้อมูล
const int CONFIRMATION = 2; //เลือกลักษณะงาน
const int SELECT_JOB= 3; //รอดึงลูกยาง
const int BACKFLUSH = 4; //ใส่รหัสซ่อมเตรื่อง
const int REWORD = 5; //นับจำนวน
const int DOWNTIME = 6; //ส่งจำนวน

int state;

void setup() {
  // โค้ดที่ใช้ตั้งค่าเริ่มต้น ทำงานครั้งเดียว
  Serial.begin(115200);
  state = WAIT_FOR_CARD;
}

void loop() {
  // โค้ดหลักที่ทำงานซ้ำไปเรื่อย ๆ

  if (state == WAIT_FOR_CARD) {
    Serial.println("กำลังรอการแตะบัตร...");
    // โค้ดสำหรับตรวจจับการแตะบัตรไปที่นี้

    // ถ้าถูกตรวจจับว่ามีการแตะบัตร
    state = CONFIRMATION;
  } else if (state == CONFIRMATION) {
    Serial.println("ตรวจจับบัตรแล้ว กดยืนยันเพื่อดำเนินการต่อ หรือยกเลิกเพื่อย้อนกลับ");
    // โค้ดสำหรับการจัดการข้อมูลการยืนยันไปที่นี้

    // ถ้าผู้ใช้ยืนยัน
    state = SELECT_JOB;
    // ถ้าผู้ใช้ยกเลิก
    // state = WAIT_FOR_CARD;
  } else if (state == SELECT_JOB) {
    Serial.println("เลือกลักษณะงาน:");
    Serial.println("1. Backflush");
    Serial.println("2. Reword");
    Serial.println("3. Downtime");

    // โค้ดสำหรับการจัดการข้อมูลการเลือกงานไปที่นี้

    // ถ้าผู้ใช้เลือกงาน
    int selectedJob = 1; // แทนที่ด้วยข้อมูลจริง
    if (selectedJob == 1 || selectedJob == 2) {
      state = BACKFLUSH;
    } else if (selectedJob == 3) {
      state = DOWNTIME;
    }
  } else if (state == BACKFLUSH) {
    Serial.println("กำลังดำเนินการ Backflush...");
    // โค้ดสำหรับกระบวนการ Backflush ไปที่นี้

    // หลังจากทำงานเสร็จสิ้น กลับไปที่สถานะรอดึงลูกยาง
    state = SELECT_JOB;
  } else if (state == DOWNTIME) {
    Serial.println("กรุณากรอกรหัสเครื่องจักร:");
    // โค้ดสำหรับการจัดการข้อมูลการกรอกรหัสเครื่องจักรไปที่นี้

    // ถ้ากรอกรหัสเครื่องจักรเสร็จสิ้น กลับไปที่สถานะรอดึงลูกยาง
    state = SELECT_JOB;
  }

  delay(1000); // ปรับ delay ตามต้องการ
}
