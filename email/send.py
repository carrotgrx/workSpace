# -*- coding: utf-8 -*-

import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart


def send_email():
    smtp_server = 'smtp.qq.com'
    port = 465
    sender_email = ''
    sender_password = '' # QQ邮箱授权码
    receiver_email = ''

    subject = 'Test Email'
    body = 'This is a test email'

    msg = MIMEMultipart()
    msg['From'] = sender_email
    msg['To'] = receiver_email
    msg['Subject'] = subject
    msg.attach(MIMEText(body, 'plain'))

    try:
        server = smtplib.SMTP_SSL(smtp_server, port)
        server.login(sender_email, sender_password)
        server.sendmail(sender_email, receiver_email, msg.as_string())
        server.quit()
        print('Email sent successfully')
    except Exception as e:
        print('Email sending failed:', str(e))


if __name__ == '__main__':
    send_email()
