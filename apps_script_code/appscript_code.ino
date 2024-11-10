var ss = SpreadsheetApp.openById('1WfHRUJbDoLhnMQkLLeNxjbquUdwxtsfdZbisAzjM9pA'); // Google Sheets ID
var sheet = ss.getSheetByName('Sheet1'); // Sheet adını burada belirtin
var timezone = "Europe/İstanbul"; // Zaman dilimini ayarlayın

function doGet(e) {
  Logger.log(JSON.stringify(e));

  // Parametre kontrolü
  if (!e.parameters.name || e.parameters.name.length === 0 || e.parameters.name[0] === 'undefined') {
    return ContentService.createTextOutput("Received data is undefined");
  }

  // Tarih ve saat bilgisi al
  var Curr_Date = new Date();
  var Curr_Time = Utilities.formatDate(Curr_Date, timezone, 'HH:mm:ss');

  // İsim bilgisi
  var name = stripQuotes(e.parameters.name[0]);

  // Yeni satır ekleme
  var nextRow = sheet.getLastRow() + 1;
  sheet.getRange("A" + nextRow).setValue(Curr_Date);
  sheet.getRange("B" + nextRow).setValue(Curr_Time);
  sheet.getRange("C" + nextRow).setValue(name);

  // Yanıt gönder
  return ContentService.createTextOutput("Card holder name is stored in column C");
}

function stripQuotes(value) {
  return value.toString().replace(/^["']|['"]$/g, "");
}
