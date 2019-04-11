<?php include '../TechHelpDesk-BackEnd/php/customerGetData.php'; ?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <link rel="stylesheet" type="text/css"
          href="technologyHelpDesk_format.css" />
    <title>Customer</title>
    
</head>

<body class="background">
    <div>
        <div id="mainBar" class="topBar">
            <div class="topBar2">
                <div class="floatLeft">
                    <h1>Technology HelpDesk - Customer Ticket System</h1>
                </div>
                <div class="floatRight">
                	<button id="btn_logout" onclick="location.href = '/TechHelpDesk-Backend/php/logout.php'">Logout</button>
                </div>
            </div>
        </div>
        
        <div id="secondaryBackGround2" class="middleBar2">
            <div class="paddingMiddle"
                 style="width: 1500px; margin: 0px; margin-right: auto; margin-left: auto;">
                <div class="sideToolPanel">
                    <h2>Tools</h2>
                    <div>
                        <button id="btn_createTicket">Create Ticket</button>
                        <button id="btn_showUserTickets" style="display:none">See Your Tickets</button>
                    </div>
                </div>
                
				<div>
					<div id="id_userTickets"> 
 						<div class="userMainPanel_ViewTicket">
 							<h3>My Tickets</h3>
 							<table border="1" class="viewTicketTable">
    							<tr class="tableHeader">
        							<td>TicketID</td>
        							<td>Title</td>
        							<td>Customer Notes</td>
        							<td>Tech Notes</td>
        							<td>Date Created</td>
                                    <td>Status</td>
    							</tr>
    						<?php
        						$userid = $_SESSION["userid"];
        						$sqlGetUserTicketInfo =
        							"SELECT tickets.id,`title`,`custnotes`, `technotes`, `date`, `ticketStatus`
        							FROM `techhelpdb`.`tickets`
        							JOIN techhelpdb.ticket_assignments on ticket_assignments.ticketid = tickets.id
        							WHERE ticket_assignments.userid = '$userid'";
        						$result = mysqli_query($db, $sqlGetUserTicketInfo);
        						
        						if (mysqli_num_rows($result) > 0)
        						{
        							while($row = mysqli_fetch_assoc($result))
        							{
        							    $ticketStatus = $row["ticketStatus"];

        							    echo '<tr id="ticketRowData">';
        								echo '<td>'. $row["id"] . '</td>';
        								echo '<td>'. $row["title"] . '</td>';
        								echo '<td>'. $row["custnotes"] . '</td>';
        								echo '<td>'. $row["technotes"] . '</td>';
        								echo '<td>'. $row["date"] . '</td>';
        								
        								if(strcasecmp($ticketStatus, 'Completed') == 0 )
        								{
        								    //Highlight row to indicate completion
        								    echo '<td class="completedTicketColor">'. $ticketStatus . '</td>';
        								}
    								    else{
    								        echo '<td>'. $ticketStatus . '</td>';
    								    }
        								    
        								echo '</tr>';
        								
        							}
        						}
        						
        						#Free result set
        						mysqli_free_result($result);
        					?>
    						</table>
                    	</div>
    				</div>
                    <div id="id_createTicket" style="display:none">
                    	<div class="userMainPanel_CreateTicket" >
                			<form action="/TechHelpDesk-BackEnd/php/add_ticket.php" method="post">
                				<table>
                					<tr class="custTicketInformation">
                						<td></td>
                						<td>
                							Title:<br> 
                							<input type="text" name="title"><br>
                						</td>
                						<td>
                							Date:<br> 
                							<input type="text" name="date" id="date" 
                												 readonly="readonly"><br>
                							<script>
                    							document.getElementById("date").value = 
                        							(new Date()).toISOString().substring(0, 10);
                    						</script>                  						
                						</td>
                						<td>
                							Technician:<br>
											<input type="text" name="technician" readonly="readonly"
                							 					placeholder="To be determined."><br>                							
                						</td>
                						<td>
    										<label for="hardwareObtain">Hardware taken in?</label>
                    						<input id="hardwareObtain" type="checkbox" value="hardwareObtained" name="hardwareObtained"/>
                    						<br>
                    						<select name="hardwareType" id="hardwareList">
                    							<option value="hardware0"></option>
                    							<option value="hardware1">hardware1</option>
                    							<option value="hardware2">hardware2</option>
                    							<option value="hardware3">hardware3</option>
                    							<option value="hardware4">hardware4</option>
                    							<option value="hardware5">hardware5</option>
                    							<option value="hardware6">hardware6</option>
                    							<option value="hardware7">hardware7</option>
                    							<option value="hardware8">hardware8</option>
                    						</select>                						
                						</td>
                					</tr>
                					<tr class="custTicketNotes">
										<td>
		                					<h2>Ticket Notes</h2>								
										</td>
										<td colspan="5">
                							<textarea name="custnotes" cols="60" rows="8" class="ticketTextBox"></textarea>
										</td>
									</tr>
									<tr>
										<td colspan="5">
                							<input type="submit" id="btn_submitTicket" value="Create New Ticket">
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

        $(document).ready(function () {
            $("#btn_showUserTickets").click(function () {
                $("#id_createTicket").hide();
				$("#id_userTickets").show();
				
                $("#btn_createTicket").show();
                $("#btn_showUserTickets").hide();
            });

            $("#btn_createTicket").click(function () {                
				$("#id_createTicket").show();
				$("#id_userTickets").hide();		
						
                
                $("#btn_showUserTickets").show();
                $("#btn_createTicket").hide();
            });            

    		
        });

    </script>

</body>
</html>
