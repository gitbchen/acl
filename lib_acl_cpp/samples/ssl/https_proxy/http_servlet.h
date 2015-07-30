#pragma once

class http_servlet : public acl::HttpServlet
{
public:
	http_servlet(acl::ostream& out, acl::polarssl_conf* conf);
	~http_servlet();

protected:
	bool doGet(acl::HttpServletRequest& req,
		acl::HttpServletResponse& res);
	bool doPost(acl::HttpServletRequest& req,
		acl::HttpServletResponse& res);
	bool doUnknown(acl::HttpServletRequest&,
		acl::HttpServletResponse& res);
	bool doError(acl::HttpServletRequest&,
		acl::HttpServletResponse& res);
	bool doConnect(acl::HttpServletRequest& req,
		acl::HttpServletResponse& res);
	bool doPut(acl::HttpServletRequest& req,
		acl::HttpServletResponse& res);
	bool doDelete(acl::HttpServletRequest& req,
		acl::HttpServletResponse& res);
	bool doHead(acl::HttpServletRequest& req,
		acl::HttpServletResponse& res);
	bool doOptions(acl::HttpServletRequest& req,
		acl::HttpServletResponse& res);

private:
	bool handled_;
	acl::string url_;
	acl::ostream& out_;
	acl::polarssl_conf* client_ssl_conf_;

	void logger_request(acl::HttpServletRequest& req);
};