<?php include '../TechHelpDesk-BackEnd/php/customerGetData.php'; ?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <link rel="stylesheet" type="text/css"
          href="technologyHelpDesk_format.css" />
    <script src="monitor.js"></script>
    <title>Ticket Monitor</title>
</head>

<body class="background">
    <div>
        <div id="mainBar" class="topBar">
            <div class="topBar2">
                <div class="floatLeft">
                    <h1>Technology HelpDesk - Monitor All Tickets</h1>
                </div>
                <div class="floatRight">
                	<button id="btn_logout" onclick="location.href = '/TechHelpDesk-Backend/php/logout.php'">Logout</button>
                </div>
            </div>
        </div>
    
        <div id="secondaryBackGround2" class="middleBar2">
            <div class="paddingMiddle" style="width: 1500px; margin: 0px; margin-right: auto; margin-left: auto;">
                <div class="sideToolPanel">
                    <h2>Tools</h2>
                    <div>
                        <button id="btn_allTicket">All Ticket</button>
                    </div>
                </div>
            	<div>
        			
        			
                    <div id="id_showSelectedTicket" >
                    	<div class="userMainPanel_UpdateTicket" >
                    	
                			<form action="/TechHelpDesk-BackEnd/php/update_ticket.php" method="post">
	        					<table border="1" class="viewTicketTable">
                                    <tr class="tableHeader">
                                    	<td>TicketID</td>
                                    	<td>UserID</td>
                                    	<td>Date Created</td>
                                    	<td>Title</td>                        	                        	
                                    	<td>Customer Notes</td>
                                    	<td>Tech Notes</td>                        	
                                    	<td>Hardware Type</td>                        	
                                    	<td>Hardware Received?</td>
                                        <td>Status</td>
                                    </tr>                                    
            						<?php            	            						
                						$selectedTicketId = htmlspecialchars($_GET["ticketId"]);
                						$_SESSION['selectedTicketIdSession'] = $selectedTicketId;
                						
                						$sqlGetSelectedTicketInfo =
                						"SELECT tickets.id, ticket_assignments.userid, `title`,`custnotes`, `technotes`, `date`, `ticketStatus`, `hardwareType`, `hardwareObtained`
                    							FROM `techhelpdb`.`tickets`
                    							JOIN techhelpdb.ticket_assignments on ticket_assignments.ticketid = tickets.id
                    						    WHERE tickets.id = '$selectedTicketId'";
            						
                						$result = mysqli_query($db, $sqlGetSelectedTicketInfo);
                						if (mysqli_num_rows($result) > 0)
                						{
                						    $date = date('Y-m-d');
                						    $twoDaysAgoFromCurrDate = date('Y-m-d', (strtotime( '-2 days', strtotime($date) ) ) );
        
                							while($row = mysqli_fetch_assoc($result))
                							{
                							    $ticketId = $row["id"];
                							    $ticketDate = $row["date"];
                							    
                							    if($ticketDate <= $twoDaysAgoFromCurrDate  )
                							    {
                							        //Highlight row to indicate priority
                							        echo '<tr id="ticketRowData" class="alertTicketRow">';
                							    }
                							    else{
                							        echo '<tr id="ticketRowData">';
                							    }
                							    
                							    echo '<td>'. $selectedTicketId . '</td>';
                								echo '<td>'. $row["userid"] . '</td>';            								
                								echo '<td>'. $row["date"] . '</td>';
                								echo '<td>'. $row["title"] . '</td>';
                								echo '<td>'. $row["custnotes"] . '</td>';
                								echo '<td>'. $row["technotes"] . '</td>';
                								echo '<td>'. $row["hardwareType"] . '</td>';
                								echo '<td>'. $row["hardwareObtained"] . '</td>';
                								echo '<td>'. $row["ticketStatus"] . '</td>';
                								echo '</tr>';
                								
                							}
                						}
                						
                						#Free result set
                						mysqli_free_result($result);
                					?>                             	                      	
									<tr>
										<td colspan="3" class="rowFont">Tech Notes</td>
										<td colspan="6">
											<textarea name="technotes" cols="100" rows="5" class="ticketTextBox"></textarea>
										</td>
									</tr>
									<tr>
										<td colspan="3" class="rowFont">Status</td>
										<td>
                    						<select name="status" id="statusList">
                    							<option value="new">new</option>
                    							<option value="Waiting for Hardware">Waiting for Hardware</option>                    							
                    							<option value="Ongoing">Ongoing</option>
                    							<option value="Completed">Completed</option>
                    						</select>  
										</td>
										<td colspan="5">
                							<input type="submit" id="btn_submitTicket" value="Update Ticket">
										</td>
									</tr>
                				</table>
                			</form>
                        </div>
                    </div>
        		</div>
       		</div>
    	</div>
        <div id="bottomBar" class="bottomBar">
            <div class="footerMessage">
                Software Engineering Project 1
                Prototype, Technology Help Desk
            </div>
        </div> 	
    </div>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script>

      //  $(document).ready(function () {
            $("#btn_allTicket").click(function () {                
				$("#id_showSelectedTicket").hide();
				$("#id_allTickets").show();		

				document.location.href = "https://techhelpdesk.azurewebsites.net/TechHelpDesk-FrontEnd/monitorV2.php";			   
                
            });            
        //});
        var selectedUserTicketID = 1;
        
        function setUserTicket(ticketId){
			selectedUserTicketID = ticketId;
        };

        function getUserTicket(){
			return selectedUserTicketID;
        };
        
        function getUserTicketInfo(ticketId) {
            $("#id_showSelectedTicket").show();
		//	$("#id_allTickets").hide();

			setUserTicket(ticketId);
			//document.location.href = "https://techhelpdesk.azurewebsites.net/TechHelpDesk-FrontEnd/monitorV2.php?ticketId=" + ticketId;
        };

        
    </script>


</body>
</html>
