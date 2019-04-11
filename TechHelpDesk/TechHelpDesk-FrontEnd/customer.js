// JavaScript Document



window.onload = function() 
{
  var c = document.getElementById('hardwareCheck')
  c.onchange = function() 
  {
    if (c.checked == true) 
	{
		document.getElementById('hardwareList').style.display = 'inline';
	}
    else 
	{
		document.getElementById('hardwareList').style.display = '';
    }
  };
};

function show(shown, hidden) {
  document.getElementById(shown).style.display='block';
  document.getElementById(hidden).style.display='none';
  return false;
}


function addRow(tableID) {

			var table = document.getElementById(tableID);

			var rowCount = table.rows.length;
			var row = table.insertRow(rowCount);

			var cell1 = row.insertCell(0);
			var element1 = document.createElement("button");
			element1.innerHTML="Edit";
			cell1.appendChild(element1);

			var cell2 = row.insertCell(1);
			cell2.innerHTML = "TicketID" + rowCount;

			var cell3 = row.insertCell(2);
			cell3.innerHTML = "Customer Name"; 
			//cell3.appendChild(element2);
			
			var cell4 = row.insertCell(3);
			cell4.innerHTML = "Description"; 
			//cell4.appendChild(element2);
			
			var cell5 = row.insertCell(4);
			cell5.innerHTML = "Date Created"; 
			//cell5.appendChild(element2);


		}

		function deleteRow(tableID) {
			try {
			var table = document.getElementById(tableID);
			var rowCount = table.rows.length;

			for(var i=0; i<rowCount; i++) {
				var row = table.rows[i];
				var chkbox = row.cells[0].childNodes[0];
				if(null != chkbox && true == chkbox.checked) {
					table.deleteRow(i);
					rowCount--;
					i--;
				}


			}
			}catch(e) {
				alert(e);
			}
		}
